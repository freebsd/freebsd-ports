# New ports collection makefile for:	freeimage
# Date created:		2005-09-01
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	freeimage
PORTVERSION=	3.10.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An open source graphics library

WRKSRC=		${WRKDIR}/FreeImage
USE_GMAKE=	yes
USE_ZIP=	yes
# convert CRLF to LF for gcc-2.95
EXTRACT_BEFORE_ARGS=	-qoa
USE_LDCONFIG=	yes

PLIST_FILES=	include/FreeImage.h \
		lib/libfreeimage.a \
		lib/libfreeimage.so \
		lib/libfreeimage.so.3

.include <bsd.port.mk>
