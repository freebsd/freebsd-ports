# New ports collection makefile for:	websvn
# Date created:				11 May 2004
# Whom:					Yuan-Chung Hsiao (ychsiao@ychsiao.idv.tw)
#
# $FreeBSD$
#

PORTNAME=	websvn
PORTVERSION=	1.60
CATEGORIES=	devel www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/14334/
DISTNAME=	WebSVN_${PORTVERSION:S/.//}

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
	${CHOWN} -R www:www ${PREFIX}/${WEBSVNDIR}
	${FIND} ${PREFIX}/${WEBSVNDIR} -type f | ${XARGS} ${CHMOD} 644

.include <bsd.port.mk>
