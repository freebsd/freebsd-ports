# New ports collection makefile for: phpPgAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phppgadmin
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpPgAdmin-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	Web Based Postgres Administration

POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/phpPgAdmin
NO_BUILD=	YES

PGADMDIR?=      www/data/phpPgAdmin
PLIST_SUB+=     PGADMDIR=${PGADMDIR}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/php4/bsd.php.mk"

do-install:
	${MKDIR} ${PREFIX}/${PGADMDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${PGADMDIR}

.include <bsd.port.post.mk>
