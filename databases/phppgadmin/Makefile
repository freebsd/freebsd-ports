# New ports collection makefile for: phpPgAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phppgadmin
PORTVERSION=	3.2.1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpPgAdmin-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Postgres Administration

USE_BZIP2=	yes
USE_PHP=	yes
WRKSRC=		${WRKDIR}/phpPgAdmin
NO_BUILD=	YES

PHP_PORT?=	www/mod_php4-twig
PGADMDIR?=      www/data/phpPgAdmin
PLIST_SUB+=     PGADMDIR=${PGADMDIR}

do-install:
	${MKDIR} ${PREFIX}/${PGADMDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${PGADMDIR}

.include <bsd.port.mk>
