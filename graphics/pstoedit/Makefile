# New ports collection makefile for:	pstodit
# Version required:	2.60p1
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/08/10 12:08:21 steve Exp $
#

DISTNAME=	pstoedit.2.60p1
PKGNAME=	pstoedit-2.60p1
CATEGORIES=	graphics print
MASTER_SITES=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5

FETCH_BEFORE_ARGS=	-t
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=    -q
EXTRACT_AFTER_ARGS=     -d ${WRKDIR}
WRKSRC=		${WRKDIR}/src
MAKEFILE=	makefile
ALL_TARGET=

MANL=	pstoedit.l

.include <bsd.port.mk>
