# New ports collection makefile for: phpPgAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phppgadmin
PORTVERSION=	3.4
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpPgAdmin-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Postgres Administration

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_PHP=	yes
WRKSRC=		${WRKDIR}/phpPgAdmin
NO_BUILD=	YES

PHP_PORT?=	${PORTSDIR}/www/mod_php4-twig
PGADMDIR?=	www/data/phpPgAdmin
PLIST_SUB+=	PGADMDIR=${PGADMDIR}

do-configure:
	${REINPLACE_CMD} -e "s|/usr/bin/pg|${LOCALBASE}/bin/pg|" \
		${WRKSRC}/conf/config.inc.php-dist
	${RM} -f ${WRKSRC}/conf/config.inc.php \
		${WRKSRC}/conf/config.inc.php-dist.bak

do-install:
	${MKDIR} ${PREFIX}/${PGADMDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${PGADMDIR}
	@[ -f ${PREFIX}/${PGADMDIR}/conf/config.inc.php ] || \
		${CP} -p ${PREFIX}/${PGADMDIR}/conf/config.inc.php-dist \
		${PREFIX}/${PGADMDIR}/conf/config.inc.php

.include <bsd.port.mk>
