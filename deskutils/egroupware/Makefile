# New ports collection makefile for:	egroupware
# Date created:        27 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	eGroupWare
PORTVERSION=	1.0.00.004
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	egroupware
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A web based GroupWare system

USE_BZIP2=	yes
USE_PHP=	pcre session xml
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/egroupware

.if defined(WITH_POSTGRESQL)
USE_PHP+=	pgsql
.endif
.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif
.if defined(WITH_IMAP)
USE_PHP+=	imap
.endif
.if defined(WITH_GD)
USE_PHP+=	gd
.endif

DEST=	${PREFIX}/www/data-dist/egroupware

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -rf

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/www/data-dist/
	${CHMOD} g+w ${DEST}/phpgwapi/images ${DEST}/fudforum
	${CHGRP} ${WWWGRP} ${DEST}/phpgwapi/images ${DEST}/fudforum

# postgresql.conf
# tcpip_socket = true
# ports = 5432
#
# pg_hba.conf
# local egroupware trust
# host egroupwaredbname all 127.0.0.1 255.255.255 md5
#
# createuser $dbuser -P -A -d
# createdb -U $dbuser $dbname
#
# Open http://localhost/egroupware/setup/index.php

.include <bsd.port.mk>
