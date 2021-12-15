PORTNAME=	sdl12-compat
PORTVERSION=	s20211214
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	SDL-1.2 compatibility layer that uses SDL 2.0 behind the scenes

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing localbase sdl
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_SDL=	sdl2
CMAKE_OFF=	SDL12DEVEL
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	SDL12TESTS
CMAKE_TESTING_TARGET=	# post-test
GH_ACCOUNT=	libsdl-org
GH_TAGNAME=	8f54fd8
SUFFIX=		-${PORTNAME:C/.*-//}
PLIST_FILES=	etc/libmap.d/${PORTNAME}.conf \
		lib/libSDL-1.2${SUFFIX}.so \
		lib/libSDL-1.2${SUFFIX}.so.0 \
		lib/libSDL-1.2${SUFFIX}.so.1.2.50 \
		"@comment lib/libSDLmain.a"

post-patch:
# Add library suffix to co-exist with sdl12 package
	@${REINPLACE_CMD} -e '/OUTPUT_NAME/s/")$$/${SUFFIX}&/' \
		${WRKSRC}/CMakeLists.txt
# <alloca.h> doesn't exist on BSDs and is included by <stdlib.h> on Linux
	@${REINPLACE_CMD} -e '/ALLOCA_H/d' \
		${WRKSRC}/include/SDL/SDL_config.h
# Drop unused dependency on libGLU
	@${REINPLACE_CMD} -e '/glu\.h/d' \
		${WRKSRC}/include/SDL/SDL_opengl.h

post-install:
# Replace sdl12 with sdl12-compat at runtime
	@${ECHO_CMD} ${PLIST_FILES:T:M*.so.?:_:S/${SUFFIX}//} $_ \
		>${STAGEDIR}${PREFIX}/etc/libmap.d/${PORTNAME}.conf

pre-test:
# Enable RPATH for test executables to avoid LD_LIBRARY_PATH
	@${REINPLACE_CMD} -i.tests -e '/CMAKE_SKIP_RPATH/d' \
		${WRKSRC}/CMakeLists.txt

post-test: # subset known to work
.for t in ver error file platform thread timer
	(cd ${TEST_WRKSRC} && ./test$t)
.endfor
	(cd ${TEST_WRKSRC} && ./testloadso libpthread.so pthread_create)
	(cd ${TEST_WRKSRC} && ./torturethread)
#	(cd ${TEST_WRKSRC} && ./testiconv) # FAIL: UCS4
#	(cd ${TEST_WRKSRC} && timeout 10 ./testlock) # hangs
#	(cd ${TEST_WRKSRC} && timeout -s ABRT 20 ./testsem mysem) # hangs
.if exists(/dev/dsp)
	(cd ${TEST_WRKSRC} && timeout --preserve-status 10 ./loopwave)
.endif
.if defined(WAYLAND_DISPLAY) || defined(DISPLAY) || exists(/dev/dri/card0)
# Text-only: finishes without interaction
. for t in vidinfo joystick keys blitspeed
	(cd ${TEST_WRKSRC} && ./test$t)
. endfor
# Window: finishes via user input or timeout
. for t in bitmap gl overlay overlay2 sprite win
	(cd ${TEST_WRKSRC} && timeout --preserve-status 3 ./test$t)
. endfor
.endif

.include <bsd.port.mk>
