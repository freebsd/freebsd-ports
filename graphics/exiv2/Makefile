# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
DISTVERSION=	0.26
PORTREVISION=	1
DISTVERSIONSUFFIX=	-trunk
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/builds/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cmake compiler:c++11-lang cpe gettext iconv pathfix localbase:ldflags
USE_LDCONFIG=	yes

LDFLAGS+=	-lintl

CMAKE_ON=	EXIV2_ENABLE_VIDEO \
		EXIV2_ENABLE_BUILD_PO
CMAKE_OFF=	EXIV2_ENABLE_BUILD_SAMPLES \
		EXIV2_ENABLE_LIBXMP

PATHFIX_CMAKELISTSTXT=	CMakeChecks.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-trunk

.include <bsd.port.mk>
