# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	dns-ui
DISTVERSION=	v0.2.7
CATEGORIES=	dns

MAINTAINER=	zi@FreeBSD.org
COMMENT=	LDAP-authenticated PowerDNS user interface by Opera

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pgsql php:mod,cli
USE_GITHUB=	yes
GH_ACCOUNT=	operasoftware
USE_PHP=	curl intl json ldap mbstring pdo_pgsql

NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		APACHE PGSQLSRV
OPTIONS_DEFAULT=	APACHE PGSQLSRV
APACHE_DESC=		Use apache as webserver
PGSQLSRV_DESC=		Use local postgres instance

APACHE_RUN_DEPENDS=	mod_php74>0:www/mod_php74
APACHE_USES=		apache:run,2.2+
PGSQLSRV_VARS=		WANT_PGSQL=server

.include <bsd.port.options.mk>

post-extract:
	${MV} ${WRKSRC}/config/config-sample.ini \
		${WRKSRC}/config/config.ini.sample

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
