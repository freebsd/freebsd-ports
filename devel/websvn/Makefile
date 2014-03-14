# Created by: Yuan-Chung Hsiao (ychsiao@ychsiao.idv.tw)
# $FreeBSD$

PORTNAME=	websvn
PORTVERSION=	2.3.3
CATEGORIES=	devel www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/49056/

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Subversion repository web frontend

USE_PHP=	iconv pcre xml
NO_BUILD=	yes

WEBSVNDIR?=	${WWWDIR_REL}

SUB_FILES=	pkg-message
SUB_LIST+=	WEBSVNDIR="${WEBSVNDIR}"
PLIST_SUB+=	WEBSVNDIR="${WEBSVNDIR}"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${WEBSVNDIR}
	(cd ${WRKSRC} \
	    && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/${WEBSVNDIR})
	${CHOWN} -R www:www ${STAGEDIR}${PREFIX}/${WEBSVNDIR}
	${FIND} ${STAGEDIR}${PREFIX}/${WEBSVNDIR} -type f -exec ${CHMOD} 644 '{}' +

post-install:
	@[ -f ${STAGEDIR}${PREFIX}/${WEBSVNDIR}/include/config.php ] \
	    || ${INSTALL_DATA} \
	    ${STAGEDIR}${PREFIX}/${WEBSVNDIR}/include/distconfig.php \
	    ${STAGEDIR}${PREFIX}/${WEBSVNDIR}/include/config.php

.include <bsd.port.mk>
