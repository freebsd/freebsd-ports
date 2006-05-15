# New ports collection makefile for:	freeimage
# Date created:		2005-09-01
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	freeimage
PORTVERSION=	3.8.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	whitekid@gmail.com
COMMENT=	An open source graphics library

WRKSRC=		${WRKDIR}/FreeImage
USE_GMAKE=	yes
USE_ZIP=	yes
# convert CRLF to LF for gcc-2.95
EXTRACT_BEFORE_ARGS=	-qoa
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
