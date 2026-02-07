PORTNAME=	anope
DISTVERSION=	2.1.16
CATEGORIES=	irc
PKGNAMESUFFIX=	-devel-${FLAVOR}

MAINTAINER=	devnull@apt322.org
COMMENT=	Set of IRC services for IRC networks (development version)
WWW=		https://www.anope.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

CONFLICTS_INSTALL=	anope

FLAVORS=	default mysql
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
USE_RC_SUBR=	anope

CMAKE_ARGS=	-DINSTDIR:STRING="${PREFIX}/anope"
CFLAGS_amd64=	-fPIC
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		NLS LDAP SQLITE REDIS XMLRPC
OPTIONS_DEFAULT=	OPENSSL SQLITE
OPTIONS_GROUP=		REGEX CRYPT
OPTIONS_GROUP_REGEX=	PCRE2 POSIX TRE
OPTIONS_GROUP_CRYPT=	ENC_POSIX ENC_ARGON
OPTIONS_SINGLE=		TLS
OPTIONS_SINGLE_TLS=	OPENSSL GNUTLS
OPTIONS_SUB=		yes

PCRE2_DESC=	Perl Compatible Regular Expressions (v2) Support
POSIX_DESC=	POSIX Basic Regular Expression Support
TRE_DESC=	TRE Regex Support
XMLRPC_DESC=	Allow modules to send and receive XMLRPC
CRYPT_DESC=	Crypt Hashing Module
ENC_ARGON_DESC=	Argon2 hashing algorithm via libargon2
ENC_POSIX_DESC=	Posix crypto hashing

NLS_USES=	gettext
LDAP_USES=	ldap
OPENSSL_USES=	ssl

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
XMLRPC_LIB_DEPENDS=	libxmlrpc.so:net/xmlrpc-c
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
ENC_ARGON_LIB_DEPENDS=	libargon2.so:security/libargon2
TRE_LIB_DEPENDS=	libtre.so:textproc/libtre

REDIS_RUN_DEPENDS=	redis>0:databases/redis

.if ${FLAVOR} == mysql
USES+=		mysql
CMAKE_ARGS+=	-DEXTRA_LIBS:STRING="${LOCALBASE}/lib/mysql/"
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

post-patch:
# Avoid conflict with C++20 <version> by adding -bin suffix
	@${REINPLACE_CMD} -i .c++20 's/version /version-bin /' \
		${WRKSRC}/include/CMakeLists.txt
.if ${FLAVOR} == mysql
	${LN} -s ${WRKSRC}/modules/extra/mysql.cpp ${WRKSRC}/modules/
.endif

post-patch-OPENSSL-on:
	${LN} -s ${WRKSRC}/modules/extra/ssl_openssl.cpp ${WRKSRC}/modules/

post-patch-GNUTLS-on:
	${LN} -s ${WRKSRC}/modules/extra/ssl_gnutls.cpp ${WRKSRC}/modules/

post-patch-LDAP-on:
	${LN} -s ${WRKSRC}/modules/extra/ldap.cpp ${WRKSRC}/modules/

post-patch-PCRE2-on:
	${LN} -s ${WRKSRC}/modules/extra/regex_pcre2.cpp ${WRKSRC}/modules/

post-patch-POSIX-on:
	${LN} -s ${WRKSRC}/modules/extra/regex_posix.cpp ${WRKSRC}/modules/

post-patch-TRE-on:
	${LN} -s ${WRKSRC}/modules/extra/regex_tre.cpp ${WRKSRC}/modules/

post-patch-SQLITE-on:
	${LN} -s ${WRKSRC}/modules/extra/sqlite.cpp ${WRKSRC}/modules/

post-patch-XMLRPC-on:
	${LN} -s ${WRKSRC}/modules/extra/xmlrpc.cpp ${WRKSRC}/modules/

post-patch-ENC_ARGON-on:
	${LN} -s ${WRKSRC}/modules/extra/enc_argon2.cpp ${WRKSRC}/modules/

post-patch-ENC_POSIX-on:
	${LN} -s ${WRKSRC}/modules/extra/enc_posix.cpp ${WRKSRC}/modules/

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/anope/data/backups
	@${MKDIR} ${STAGEDIR}${PREFIX}/anope/logs

.include <bsd.port.mk>
