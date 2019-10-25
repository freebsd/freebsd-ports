# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
DISTVERSION=	0.27.2
DISTVERSIONSUFFIX=	-Source
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://www.exiv2.org/builds/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cmake compiler:c++11-lang cpe gettext iconv pathfix localbase:ldflags
USE_LDCONFIG=	yes

LDFLAGS+=	-lintl

CMAKE_ON=	EXIV2_ENABLE_VIDEO \
		EXIV2_ENABLE_NLS
CMAKE_OFF=	EXIV2_ENABLE_LIBXMP

OPTIONS_DEFINE=	SAMPLE
OPTIONS_SUB=	yes

SAMPLE_DESC=	Include sample applications
SAMPLE_CMAKE_BOOL=	EXIV2_BUILD_SAMPLES

PATHFIX_CMAKELISTSTXT=	CMakeChecks.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-Source

.include <bsd.port.mk>
