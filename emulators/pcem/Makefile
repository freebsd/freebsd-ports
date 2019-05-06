# $FreeBSD$

PORTNAME=	pcem
DISTVERSION=	14
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/pcem_emulator/pcem/get/
DISTNAME=	faf5d6423060

MAINTAINER=	darkfm@vera.com.uy
COMMENT=	PC/PC-Compatible low-level emulator striving for accuracy

LICENSE=	GPLv2

LIB_DEPENDS=	libGL.so:graphics/mesa-libs \
		libopenal.so:audio/openal-soft \
		libwx_gtk3u_core-3.0.so:x11-toolkits/wxgtk30 \
		libSDL2.so:devel/sdl20

USES=		autoreconf compiler gmake openal:soft pkgconfig sdl zip
USE_WX=		3.0
USE_SDL=	sdl2

WRKSRC=		${WRKDIR}/pcem_emulator-pcem-faf5d6423060/
PATCHDIR=files
PLIST_FILES=	bin/pcem
CONFIGURE_ARGS=	--enable-release-build --with-wx-config=wxgtk3u-3.0-config
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	amd64

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300000
LDFLAGS+=	-fuse-ld=bfd
.endif

.include <bsd.port.mk>
