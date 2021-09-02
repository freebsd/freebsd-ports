PORTNAME=	sdl12-compat
PORTVERSION=	s20210901
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	SDL-1.2 compatibility layer that uses SDL 2.0 behind the scenes

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS_INSTALL=	sdl

USES=		cmake:testing gl localbase sdl
USE_GITHUB=	yes
USE_GL=		glu
USE_LDCONFIG=	yes
USE_SDL=	sdl2
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	SDL12TESTS
CMAKE_TESTING_TARGET=	# post-test
GH_ACCOUNT=	libsdl-org
GH_TAGNAME=	dae1119

post-patch:
# Replace sdl12 for pkg-config consumers a la sdl-config
	@${REINPLACE_CMD} -e '/DESTINATION/s/pkgconfig/& RENAME sdl.pc/' \
		${WRKSRC}/CMakeLists.txt
# <alloca.h> doesn't exist on BSDs and is included by <stdlib.h> on Linux
	@${REINPLACE_CMD} -e '/ALLOCA_H/d' \
		${WRKSRC}/include/SDL/SDL_config.h

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
