# New ports collection makefile for:	pstodit
# Version required:	3.11
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	pstoedit_3_11
PKGNAME=	pstoedit-3.11
CATEGORIES=	graphics print
MASTER_SITES=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/

MAINTAINER=	jseger@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5

FETCH_BEFORE_ARGS=	-t
USE_ZIP=		yes
WRKSRC=		${WRKDIR}/pstoedit_3.11/src
MAKEFILE=	makefile
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstoedit ${PREFIX}/bin

.include <bsd.port.mk>
