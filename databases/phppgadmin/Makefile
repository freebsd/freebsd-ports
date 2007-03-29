# New ports collection makefile for: phpPgAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phppgadmin
PORTVERSION=	4.1.1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpPgAdmin-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Postgres Administration

USE_BZIP2=	YES
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	pgsql pcre session
.endif
NO_BUILD=	YES
PGADMDIR?=	www/phpPgAdmin
PLIST_SUB+=	PGADMDIR=${PGADMDIR}
PGADMOLDDIR?=	www/data-dist/phpPgAdmin
PLIST_SUB+=	PGADMOLDDIR=${PGADMOLDDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting PGADMDIR in /etc/make.conf"

do-configure:
	${REINPLACE_CMD} -e "s|/usr/bin/pg|${LOCALBASE}/bin/pg|" \
		${WRKSRC}/conf/config.inc.php-dist
	${RM} -f ${WRKSRC}/conf/config.inc.php \
		${WRKSRC}/conf/config.inc.php-dist.bak

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/${PGADMDIR}
	${RM} -f ${WRKSRC}/classes/database/Postgres81.php.orig
	${CP} -Rp ${WRKSRC}/ ${PREFIX}/${PGADMDIR}/
.if exists(${DESTDIR}${PREFIX}/${PGADMOLDDIR}/conf/config.inc.php)
	${CP} -np ${DESTDIR}${PREFIX}/${PGADMOLDDIR}/conf/config.inc.php \
		${PREFIX}/${PGADMDIR}/conf/config.inc.php
.endif
	${CP} -np ${PREFIX}/${PGADMDIR}/conf/config.inc.php-dist \
		${PREFIX}/${PGADMDIR}/conf/config.inc.php

.include <bsd.port.post.mk>
