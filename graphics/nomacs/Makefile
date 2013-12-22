# $FreeBSD$

PORTNAME=	nomacs
PORTVERSION=	1.6.2
CATEGORIES=	graphics
MASTER_SITES=	SF/nomacs/nomacs-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	bsd@tuxproject.de
COMMENT=	Small, fast and free image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libsysinfo.so:${PORTSDIR}/devel/libsysinfo

USE_BZIP2=	yes
USES=		cmake desktop-file-utils dos2unix pkgconfig
USE_QT4=	gui network linguist_build moc_build \
		qmake_build rcc_build uic_build
DOS2UNIX_REGEX=	.*\.(cpp|h|txt)

WRKTOP=		${WRKDIR}
WRKSUBDIR=	${DISTNAME:S,-source,,}
WRKSRC=		${WRKTOP}/${WRKSUBDIR}

OPTIONS_DEFINE=	RAW TIFF
OPTIONS_DEFAULT=	RAW TIFF

RAW_LIB_DEPENDS=	libraw.so:${PORTSDIR}/graphics/libraw \
			libopencv_core.so:${PORTSDIR}/graphics/opencv-core
RAW_CMAKE_OFF=		-DENABLE_RAW=0

TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_CMAKE_OFF=		-DENABLE_TIFF=0

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
