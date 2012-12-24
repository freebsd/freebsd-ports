# Created by: Janky Jay <ek@purplehat.org>
#
# $FreeBSD$
#

PORTNAME=	frontaccounting
DISTVERSION=	2.3.13
CATEGORIES=	finance www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	frontaccounting/FrontAccounting-2.3/${PORTVERSION}

MAINTAINER=	ek@purplehat.org
COMMENT=	Simple, powerful system for the entire ERP chain

USE_GETTEXT=	yes
USE_MYSQL=	yes
USE_PHP+=	mysql mysqli openssl session

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	pkg-install pkg-deinstall pkg-message
PORTDOCS=	*

SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

OPTIONS_DEFINE=	APACHE LIGHTTPD MYSQL
OPTIONS_DEFAULT=	APACHE MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	mysqld_safe:${PORTSDIR}/databases/mysql55-server
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCSARGS=
.else
PORTDOCSARGS=	'-not -path "./docs*"'
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR} ${PORTDOCSARGS}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
