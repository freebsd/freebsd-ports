# New ports collection makefile for:	websvn
# Date created:				11 May 2004
# Whom:					Yuan-Chung Hsiao (ychsiao@ychsiao.idv.tw)
#
# $FreeBSD$
#

PORTNAME=	websvn
PORTVERSION=	1.61
CATEGORIES=	devel www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/14334/
DISTNAME=	WebSVN_${PORTVERSION:S/.//}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Subversion repository web frontend

USE_PHP=	pcre zlib
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/WebSVN

WEBSVNDIR?=	www/data/WebSVN
PLIST=		${WRKDIR}/pkg-plist

pre-install:
	@${TR} -d '\r' < ${WRKSRC}/include/distconfig.inc > ${WRKSRC}/include/config.inc
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WEBSVNDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WEBSVNDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WEBSVNDIR} >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${WEBSVNDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${WEBSVNDIR}
	${CHOWN} -R www:www ${PREFIX}/${WEBSVNDIR}
	${FIND} ${PREFIX}/${WEBSVNDIR} -type f | ${XARGS} ${CHMOD} 644

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
