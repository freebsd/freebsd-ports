# New ports collection makefile for:	wmstock
# Date created:		19 Jun 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmstock
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	finance windowmaker
MASTER_SITES=	http://mattfischer.com/wmstock/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cool WindowMaker Dockapp that shows stock ticker(s)

USE_X_PREFIX=	yes
USE_XPM=	yes

WRKSRC=		${WRKDIR}/wmstock/src
USE_GMAKE=	yes
MAN1=		wmstock.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmstock ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/getquote ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmstock.1x ${PREFIX}/man/man1/wmstock.1

.include <bsd.port.mk>
