PORTNAME=	anope
DISTVERSION=	2.0.18
CATEGORIES=	irc

MAINTAINER=	devnull@apt322.org
COMMENT=	Set of IRC services for IRC networks
WWW=		https://www.anope.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=		cmake localbase:ldflags shebangfix
USE_GITHUB=	yes
USE_RC_SUBR=	anope
SHEBANG_FILES=	${WRKSRC}/src/tools/*.sh

CMAKE_ARGS=	-DINSTDIR:STRING="${PREFIX}/anope"
CFLAGS_amd64=	-fPIC

CONFLICTS_INSTALL=	anope-devel

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		GNUTLS LDAP MYSQL NLS OPENSSL PCRE POSIX REDIS SASL \
			SQLITE STATS TRE
OPTIONS_DEFAULT=	MYSQL OPENSSL POSIX
OPTIONS_SUB=		yes
POSIX_DESC=		POSIX Regex Module
STATS_DESC=		Channel Statistics Module
TRE_DESC=		Tre Regex Module

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

LDAP_USES=	ldap

MYSQL_USES=	mysql
MYSQL_CMAKE_ON=	-DEXTRA_LIBS:STRING="${LOCALBASE}/lib/mysql/"

NLS_USES=	gettext

OPENSSL_USES=	ssl

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

REDIS_RUN_DEPENDS=	redis>=0:databases/redis

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

SQLITE_USES=	sqlite

TRE_LIB_DEPENDS=	libtre.so:textproc/libtre

post-patch:
# Avoid conflict with C++20 <version> by adding -bin suffix
	@${REINPLACE_CMD} -i .c++20 's/version /version-bin /' \
		${WRKSRC}/include/CMakeLists.txt

post-patch-GNUTLS-on:
	${LN} -s ${WRKSRC}/modules/extra/m_ssl_gnutls.cpp ${WRKSRC}/modules/

post-patch-LDAP-on:
	${LN} -s ${WRKSRC}/modules/extra/m_ldap.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_ldap_authentication.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_ldap_oper.cpp ${WRKSRC}/modules/

post-patch-MYSQL-on:
	${LN} -s ${WRKSRC}/modules/extra/m_mysql.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_sql_authentication.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_sql_log.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_sql_oper.cpp ${WRKSRC}/modules/

post-patch-OPENSSL-on:
	${LN} -s ${WRKSRC}/modules/extra/m_ssl_openssl.cpp ${WRKSRC}/modules/

post-patch-PCRE-on:
	${LN} -s ${WRKSRC}/modules/extra/m_regex_pcre2.cpp ${WRKSRC}/modules/

post-patch-POSIX-on:
	${LN} -s ${WRKSRC}/modules/extra/m_regex_posix.cpp ${WRKSRC}/modules/

post-patch-SQLITE-on:
	${LN} -s ${WRKSRC}/modules/extra/m_sqlite.cpp ${WRKSRC}/modules/

post-patch-STATS-on:
	${LN} -s ${WRKSRC}/modules/extra/stats ${WRKSRC}/modules/

post-patch-TRE-on:
	${LN} -s ${WRKSRC}/modules/extra/m_regex_tre.cpp ${WRKSRC}/modules/

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/anope/data/backups
	@${MKDIR} ${STAGEDIR}${PREFIX}/anope/logs

.include <bsd.port.mk>
