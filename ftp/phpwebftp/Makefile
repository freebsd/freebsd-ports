# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	phpwebftp
PORTVERSION=	3.3b
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/phpWebFTP/phpWebFTP%203.3
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	coco@executive-computing.de
COMMENT=	Set of PHP-scripts to manage FTP over the web

LICENSE=	GPLv2

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
USE_PHP=	ftp
WRKSRC=		${WRKDIR}/${PORTNAME}

PHPWEBFTPDIR?=	${WWWDIR_REL}
PLIST_SUB+=	PHPWEBFTPDIR=${PHPWEBFTPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

post-patch:
	@${FIND} -d ${WRKSRC} -name CVS -type d -exec ${RM} -R {} \;
	@${RM} ${WRKSRC}/img/Thumbs.db
	@${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php.sample

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHPWEBFTPDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PHPWEBFTPDIR})

.include <bsd.port.mk>
