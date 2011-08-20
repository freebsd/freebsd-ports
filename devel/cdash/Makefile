# New ports collection Makefile for:	cdash
# Date created:				12 August 2011
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	cdash
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cdash.org/download/
DISTNAME=	CDash-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A web-based software testing server

LICENSE=	BSD

OPTIONS=	MYSQL	"Use MySQL" on \
		PGSQL	"Use PostgreSQL" off

USE_ZIP=	yes
USE_PHP=	curl gd xsl
USE_APACHE_RUN=	20+

NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST+=	DB_TYPE=${DB_TYPE}

.include <bsd.port.options.mk>

.if (!defined(WITH_MYSQL) && !defined(WITH_PGSQL)) || (defined(WITH_MYSQL) && defined(WITH_PGSQL))
IGNORE=		please run 'make config' and select either MYSQL or PGSQL, but not both
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
USE_PHP+=	mysql
DB_TYPE=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
USE_PHP+=	pgsql
DB_TYPE=	pgsql
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%DB_TYPE%%|${DB_TYPE}|' ${WRKSRC}/cdash/config.local.php

do-install:
	${MKDIR} ${PREFIX}/www/CDash
	${RM} -f ${WRKSRC}/cdash/config.local.php.bak
	${RM} -f ${WRKSRC}/cdash/config.local.php.orig
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${PREFIX}/www/CDash
	${CHOWN} www ${PREFIX}/www/CDash/backup ${PREFIX}/www/CDash/rss

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
