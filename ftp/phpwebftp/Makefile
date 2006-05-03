# New ports collection makefile for:	phpwebftp
# Date created:		2005-09-15
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	phpwebftp
PORTVERSION=	3.3
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpwebftp
DISTNAME=	${PORTNAME}33

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	A set of PHP-scripts to manage FTP over the web

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	ftp
PHPWEBFTPDIR?=	www/data-dist/${PORTNAME}
PLIST_SUB+=	PHPWEBFTPDIR=${PHPWEBFTPDIR}
WRKSRC=	${WRKDIR}/${PORTNAME}

do-configure:
	@${FIND} -d ${WRKSRC} -name CVS -type d -print0 | ${XARGS} -0 ${RM} -R

do-install:
	${MKDIR} ${PREFIX}/${PHPWEBFTPDIR}
	@cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${PHPWEBFTPDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(php|html|css|gif|js)" \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/${PHPWEBFTPDIR}/{}" \;
	@${CHGRP} -R ${WWWGRP} ${PREFIX}/${PHPWEBFTPDIR}

.include <bsd.port.mk>
