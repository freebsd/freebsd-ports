# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
DISTVERSION=	0.26
DISTVERSIONSUFFIX=	-trunk
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/builds/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cmake:outsource cpe gettext iconv pathfix
USE_LDCONFIG=	yes

CMAKE_ON=	EXIV2_ENABLE_VIDEO \
		EXIV2_ENABLE_BUILD_PO
CMAKE_OFF=	EXIV2_ENABLE_BUILD_SAMPLES \
		EXIV2_ENABLE_LIBXMP

PATHFIX_CMAKELISTSTXT=	CMakeChecks.txt

CFLAGS_powerpc64=	-mminimal-toc

WRKSRC=		${WRKDIR}/${PORTNAME}-trunk

.include <bsd.port.mk>
