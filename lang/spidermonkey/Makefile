# Ports collection makefile for:	spidermonkey
# Date created:	Fri Apr 18, 2003
# Whom:	Dan Rench (citric@cubicone.tmetic.com)
#
# $FreeBSD$

PORTNAME=	js
PORTVERSION=	1.5.p5
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	js
DISTNAME=	js-1.5-rc5a

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	A standalone JavaScript interpreter from the Mozilla project

CONFLICTS=	njs-*

USE_GMAKE=	YES

post-extract:
	${MV} ${WRKDIR}/js/src ${WRKSRC} && \
	${RM} -rf js && \
	${CP} ${WRKSRC}/config/Linux_All.mk \
		${WRKSRC}/config/`uname -s``uname -r`.mk && \
	${CP} ${WRKSRC}/Makefile.ref ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/`uname -s``uname -r`_DBG.OBJ/js \
		${PREFIX}/bin

.include <bsd.port.mk>
