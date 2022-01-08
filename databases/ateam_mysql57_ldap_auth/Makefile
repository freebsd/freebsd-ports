# Created by: Ganbold Tsagaankhuu <ganbold@FreeBSD.org>

PORTNAME=	ateam_mysql57_ldap_auth
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	ganbold@FreeBSD.org
COMMENT=	A-Team MySQL LDAP authentication plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_WITH_MYSQL=	56 80 101m 102m 103m

LIB_DEPENDS=	libconfig.so:devel/libconfig

USES=		compiler:c++11-lang gmake mysql:57,client,server
USE_OPENLDAP=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ateamsystems
GH_TAGNAME=	f6d79fb

PLIST_FILES=	lib/mysql/plugin/auth_ldap.so \
		"@sample etc/ateam_mysql_ldap_auth.conf.sample"
PORTDOCS=	README INSTALL

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

MAKE_ARGS=	CC="${CC}"

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
