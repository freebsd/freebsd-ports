# New ports collection makefile for:	pstodit
# Version required:	2.60p1
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/07/16 06:35:29 tg Exp $
#

DISTNAME=	pstoedit.2.60p1
PKGNAME=	pstoedit-2.60p1
CATEGORIES=	graphics print
MASTER_SITES=	http://www.geocities.com/SiliconValley/Network/1958/
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5

BROKEN=		fetch

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=    -q
EXTRACT_AFTER_ARGS=     -d ${WRKDIR}
WRKSRC=		${WRKDIR}/src
MAKEFILE=	makefile
ALL_TARGET=

MANL=	pstoedit.l

.include <bsd.port.mk>
