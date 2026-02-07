PORTNAME=	dns-ui
DISTVERSION=	v0.2.8
CATEGORIES=	dns

MAINTAINER=	zi@FreeBSD.org
COMMENT=	LDAP-authenticated PowerDNS user interface by Opera
WWW=		https://github.com/operasoftware/dns-ui/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pgsql php:cli
USE_GITHUB=	yes
GH_ACCOUNT=	operasoftware
USE_PHP=	curl intl ldap mbstring pdo_pgsql

NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		APACHE PGSQLSRV
OPTIONS_DEFAULT=	APACHE PGSQLSRV
APACHE_DESC=		Use apache as webserver
PGSQLSRV_DESC=		Use local postgres instance

APACHE_USES=		apache:run php:mod
APACHE_USES_OFF=	php:web
PGSQLSRV_VARS=		WANT_PGSQL=server

.include <bsd.port.options.mk>

post-extract:
	${MV} ${WRKSRC}/config/config-sample.ini \
		${WRKSRC}/config/config.ini.sample

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
