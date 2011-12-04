# New ports collection makefile for:	websvn
# Date created:				11 May 2004
# Whom:					Yuan-Chung Hsiao (ychsiao@ychsiao.idv.tw)
#
# $FreeBSD$
#

PORTNAME=	websvn
PORTVERSION=	2.3.2
CATEGORIES=	devel www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/48737/

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Subversion repository web frontend

USE_PHP=	iconv pcre xml
NO_BUILD=	yes

WEBSVNDIR?=	${WWWDIR_REL}

SUB_FILES=	pkg-message
SUB_LIST+=	WEBSVNDIR="${WEBSVNDIR}"
PLIST_SUB+=	WEBSVNDIR="${WEBSVNDIR}"

do-install:
	${MKDIR} ${PREFIX}/${WEBSVNDIR}
	(cd ${WRKSRC} \
	    && ${COPYTREE_SHARE} \* ${PREFIX}/${WEBSVNDIR})
	${CHOWN} -R www:www ${PREFIX}/${WEBSVNDIR}
	${FIND} ${PREFIX}/${WEBSVNDIR} -type f -exec ${CHMOD} 644 '{}' +

post-install:
	@${CAT} ${PKGMESSAGE}
	@[ -f ${PREFIX}/${WEBSVNDIR}/include/config.php ] \
	    || ${INSTALL_DATA} \
	    ${PREFIX}/${WEBSVNDIR}/include/distconfig.php \
	    ${PREFIX}/${WEBSVNDIR}/include/config.php

.include <bsd.port.mk>
