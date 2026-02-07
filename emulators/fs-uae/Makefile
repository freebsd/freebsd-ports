PORTNAME=	fs-uae
PORTVERSION=	3.1.66
CATEGORIES=	emulators
MASTER_SITES=	https://fs-uae.net/files/FS-UAE/Stable/${PORTVERSION}/

MAINTAINER=	sirdice@gmail.com
COMMENT=	Amiga emulator
WWW=		https://fs-uae.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libmpeg2.so:multimedia/libmpeg2 \
		libopenal.so:audio/openal-soft \
		libpng.so:graphics/png

USES=		compiler:c11 desktop-file-utils gettext gl gmake gnome \
		localbase pkgconfig sdl shared-mime-info tar:xz xorg

USE_SDL=	sdl2
USE_GL=		gl
USE_GNOME=	glib20
USE_XORG=	x11

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-c++11-narrowing
LDFLAGS_i386=	-Wl,-znotext
USE_CXXSTD=    gnu++98

OPTIONS_DEFINE=	DOCS DEBUG
OPTIONS_DEFINE_i386=	JIT
OPTIONS_DEFINE_amd64=	JIT

JIT_DESC=	Enable JIT compiler (experimental)
JIT_CONFIGURE_ENABLE=	jit

.include <bsd.port.pre.mk>

# The following is actually meant for lld 15.0 and later, but the ports
# framework does not support LINKER_TYPE and LINKER_VERSION yet.
.if ${COMPILER_TYPE} == "clang"
# Turn off checking of dynamic relocations, to avoid lld diagnostics about
# possibly incorrect addend values.
LDFLAGS_i386+=  -Wl,--no-check-dynamic-relocations
.endif

# JIT is not supported on non-x86 make sure it's off
.if ${ARCH} != amd64 && ${ARCH} != i386
CONFIGURE_ARGS+=	--disable-jit
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= bind|= ::bind|' \
		${WRKSRC}/src/od-fs/bsdsocket_posix.cpp \
		${WRKSRC}/src/support/socket.cpp
	@${REINPLACE_CMD} -e 's|return NULL|return 0|' \
		${WRKSRC}/src/memory.cpp
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1500019 || ( ${OSVERSION} >= 1401500 && ${OSVERSION} < 1500000 ))
	# These versions moved ftime() from libcompat to libutil
	@${REINPLACE_CMD} -e 's|-lcompat|-lutil|' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
