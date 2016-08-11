# Created by: Yuan-Chung Hsiao (ychsiao@ychsiao.idv.tw)
# $FreeBSD$

PORTNAME=	websvn
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/49056/

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Subversion repository web frontend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_powerpc64=	Does not build

USES=		cpe
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
	${FIND} ${STAGEDIR}${PREFIX}/${WEBSVNDIR} -type f -exec ${CHMOD} 644 '{}' +

.include <bsd.port.mk>
