# New ports collection makefile for: phpPgAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phppgadmin
PORTVERSION=	3.5.4
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpPgAdmin-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Postgres Administration

USE_REINPLACE=	yes
USE_BZIP2=	yes
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	pgsql pcre session
.endif
WRKSRC=		${WRKDIR}/phpPgAdmin
NO_BUILD=	YES
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
