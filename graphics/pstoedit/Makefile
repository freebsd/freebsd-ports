# New ports collection makefile for:	pstodit
# Version required:	3.11
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1998/08/10 13:26:34 steve Exp $
#

DISTNAME=	pstoedit_3_11
PKGNAME=	pstoedit-3.11
CATEGORIES=	graphics print
MASTER_SITES=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/
EXTRACT_SUFX=	.zip

MAINTAINER=	jseger@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5

FETCH_BEFORE_ARGS=	-t
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=    -q
EXTRACT_AFTER_ARGS=     -d ${WRKDIR}
WRKSRC=		${WRKDIR}/pstoedit_3.11/src
MAKEFILE=	makefile
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstoedit ${PREFIX}/bin

.include <bsd.port.mk>
