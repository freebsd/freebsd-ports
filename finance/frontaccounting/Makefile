# Created by: Janky Jay <ek@purplehat.org>
# $FreeBSD$

PORTNAME=	frontaccounting
DISTVERSION=	2.3.22
CATEGORIES=	finance www
MASTER_SITES=	SF/${PORTNAME}/FrontAccounting-2.3/${PORTVERSION}

MAINTAINER=	ek@purplehat.org
COMMENT=	Simple, powerful system for the entire ERP chain

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/license.txt

USES=		cpe gettext
USE_MYSQL=	yes
USE_PHP+=	mysql mysqli openssl session

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	pkg-deinstall pkg-message

OPTIONS_DEFINE=	APACHE LIGHTTPD MYSQL NLS
OPTIONS_DEFAULT=	APACHE MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
WANT_PHP_WEB=yes
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	server
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCSARGS=
.else
PORTDOCSARGS=	'-not -path "./doc*"'
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} ${PORTDOCSARGS}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
