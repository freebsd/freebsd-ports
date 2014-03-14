# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	phpwebftp
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A set of PHP-scripts to manage FTP over the web

USES=		zip
NO_BUILD=	yes
USE_PHP=	ftp
PHPWEBFTPDIR?=	www/${PORTNAME}
PLIST_SUB+=	PHPWEBFTPDIR=${PHPWEBFTPDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_DIRE=	${INSTALL} -d -m 0755 -o ${WWWOWN} -g ${WWWGRP}
INSTALL_FILE=	${INSTALL} -m 0644 -o ${WWWOWN} -g ${WWWGRP}

NO_STAGE=	yes
post-extract:
	@${FIND} -d ${WRKSRC} -name CVS -type d -exec ${RM} -R "{}" \;

do-install:
	${INSTALL_DIRE} ${PREFIX}/${PHPWEBFTPDIR}
	@cd ${WRKSRC} && \
		${FIND} * -type d -exec ${INSTALL_DIRE} "${PREFIX}/${PHPWEBFTPDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(php|html|css|gif|js)" \
			-exec ${INSTALL_FILE} "{}" "${PREFIX}/${PHPWEBFTPDIR}/{}" \;
.include <bsd.port.mk>
