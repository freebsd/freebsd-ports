PORTNAME=	ateam_mysql_ldap_auth
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	ganbold@FreeBSD.org
COMMENT=	A-Team MySQL LDAP authentication plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libconfig.so:devel/libconfig

USE_OPENLDAP=	yes
USES=		gmake mysql:client,server

IGNORE_WITH_MYSQL=	57 80 101m 102m 103m 57p 57w

USE_GITHUB=	yes
GH_ACCOUNT=	ateamsystems
GH_TAGNAME=	f6a1a5d

PLIST_FILES=	lib/mysql/plugin/auth_ldap.so \
		"@sample etc/ateam_mysql_ldap_auth.conf.sample"
PORTDOCS=	README INSTALL

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mysql/plugin
	${INSTALL_PROGRAM} ${WRKSRC}/src/auth_ldap.so \
		${STAGEDIR}${PREFIX}/lib/mysql/plugin
	${INSTALL_DATA} ${WRKSRC}/ateam_mysql_ldap_auth.conf \
		${STAGEDIR}${PREFIX}/etc/ateam_mysql_ldap_auth.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
