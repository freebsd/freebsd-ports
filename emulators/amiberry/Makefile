PORTNAME=	amiberry
DISTVERSIONPREFIX=	v
DISTVERSION=	7.1.1
CATEGORIES=	emulators

MAINTAINER=	polyduekes@proton.me
COMMENT=	Optimized Amiga emulator
WWW=		https://amiberry.com/ \
		https://github.com/BlitterStudio/amiberry

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 riscv64

BUILD_DEPENDS=	${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo
LIB_DEPENDS=	libenet.so:net/enet \
		libFLAC.so:audio/flac \
		libmpeg2.so:multimedia/libmpeg2 \
		libmpg123.so:audio/mpg123 \
		libpng.so:graphics/png \
		libportmidi.so:audio/portmidi \
		libserialport.so:devel/libserialport \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		cmake desktop-file-utils ninja pkgconfig sdl shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	BlitterStudio
USE_SDL=	image2 sdl2 ttf2

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
