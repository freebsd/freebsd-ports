# New ports collection makefile for:	websvn
# Date created:				11 May 2004
# Whom:					Yuan-Chung Hsiao (ychsiao@ychsiao.idv.tw)
#
# $FreeBSD$
#

PORTNAME=	websvn
PORTVERSION=	1.38
CATEGORIES=	devel www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/10659/
DISTNAME=	WebSVN

MAINTAINER=	ychsiao@ychsiao.idv.tw
COMMENT=	Subversion repository web frontend

USE_PHP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/WebSVN

WEBSVNDIR?=	www/data/WebSVN

PLIST_SUB+=	WEBSVNDIR=${WEBSVNDIR}

do-install:
	${MKDIR} ${PREFIX}/${WEBSVNDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${WEBSVNDIR}
	${CHOWN} www:www ${PREFIX}/${WEBSVNDIR}

.include <bsd.port.mk>
