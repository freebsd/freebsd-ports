# $FreeBSD$

PORTNAME=	nomacs
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/nomacs/nomacs-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	bsd@tuxproject.de
COMMENT=	Small, fast and free image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libsysinfo.so:${PORTSDIR}/devel/libsysinfo

USE_BZIP2=	yes
USES=		cmake desktop-file-utils pkgconfig
USE_QT4=	gui network linguist_build moc_build \
		qmake_build rcc_build uic_build
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(cpp|h|txt)

WRKTOP=		${WRKDIR}
WRKSUBDIR=	${DISTNAME:S,-source,,}
WRKSRC=		${WRKTOP}/${WRKSUBDIR}

OPTIONS_DEFINE=	RAW TIFF
OPTIONS_DEFAULT=	RAW TIFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRAW}
LIB_DEPENDS+=	libraw.so:${PORTSDIR}/graphics/libraw \
		libopencv_core.so:${PORTSDIR}/graphics/opencv-core
.else
CMAKE_ARGS+=	-DENABLE_RAW=0
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:${PORTSDIR}/graphics/tiff
.else
CMAKE_ARGS+=	-DENABLE_TIFF=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
