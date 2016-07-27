# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
PORTVERSION=	0.25
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cmake:outsource cpe gettext iconv pathfix
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DEXIV2_ENABLE_VIDEO:BOOL=TRUE \
		-DEXIV2_ENABLE_BUILD_PO:BOOL=TRUE \
		-DEXIV2_ENABLE_BUILD_SAMPLES:BOOL=FALSE

PATHFIX_CMAKELISTSTXT=	CMakeChecks.txt

CFLAGS_powerpc64=	-mminimal-toc

.include <bsd.port.mk>
