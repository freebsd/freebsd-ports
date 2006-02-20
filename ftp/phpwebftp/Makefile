# New ports collection makefile for:	phpwebftp
# Date created:		2005-09-15
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	phpwebftp
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpwebftp
DISTNAME=	phpWebFTP32
EXTRACT_SUFX=	.zip

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	A set of PHP-scripts to manage FTP over the web

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	ftp
PHPWEBFTPDIR?=	www/data/phpWebFTP
PLIST_SUB+=	PHPWEBFTPDIR=${PHPWEBFTPDIR}
WRKSRC=	${WRKDIR}/phpWebFTP

do-configure:
	@${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php.bak
	@${CAT} ${WRKSRC}/config.inc.php.bak | ${TR} -d '\015' > ${WRKSRC}/config.inc.php && \
		${RM} ${WRKSRC}/config.inc.php.bak
	@${FIND} -d ${WRKSRC} -name CVS -type d -print0 | ${XARGS} -0 ${RM} -R

do-install:
	@${MKDIR} ${PREFIX}/${PHPWEBFTPDIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${PHPWEBFTPDIR}
	@${CHGRP} -R ${WWWGRP} ${PREFIX}/${PHPWEBFTPDIR}

.include <bsd.port.mk>
