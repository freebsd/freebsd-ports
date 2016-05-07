# Created by: mat
# $FreeBSD$

PORTNAME=	anope
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	irc

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Set of IRC services for IRC networks

LICENSE=	GPLv2

USES=		cmake:outsource shebangfix
CMAKE_ARGS+=	-DINSTDIR:STRING="${LOCALBASE}/anope"
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
SHEBANG_FILES=	${WRKSRC}/src/tools/*.sh

USE_GITHUB=	yes

USE_RC_SUBR=	anope

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GNUTLS LDAP MYSQL NLS OPENSSL PCRE POSIX SASL SQLITE STATS TRE
OPTIONS_DEFAULT=	MYSQL OPENSSL POSIX
POSIX_DESC=	POSIX Regex Module
STATS_DESC=	Channel Statistics Module
TRE_DESC=	Tre Regex Module

NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
PLIST_SUB+=	GNUTLS=""
LIB_DEPENDS+=	libgnutls.so:security/gnutls
.else
PLIST_SUB+=	GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
PLIST_SUB+=	LDAP=""
USE_OPENLDAP=	yes
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	yes
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
PLIST_SUB+=	OPENSSL=""
OPENSSL_USE=	openssl=yes
.else
PLIST_SUB+=	OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
PLIST_SUB+=	PCRE=""
LIB_DEPENDS+=	libpcre.so:devel/pcre
.else
PLIST_SUB+=	PCRE="@comment "
.endif

.if ${PORT_OPTIONS:MPOSIX}
PLIST_SUB+=	POSIX=""
.else
PLIST_SUB+=	POSIX="@comment "
.endif

.if ${PORT_OPTIONS:MSASL}
PLIST_SUB+=	SASL=""
LIB_DEPENDS+=	libsasl2.so:security/cyrus-sasl2
.else
PLIST_SUB+=	SASL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
PLIST_SUB+=	SQLITE=""
USES+=		sqlite
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MSTATS}
PLIST_SUB+=	STATS=""
.else
PLIST_SUB+=	STATS="@comment "
.endif

.if ${PORT_OPTIONS:MTRE}
PLIST_SUB+=	TRE=""
LIB_DEPENDS+=	libtre.so:textproc/libtre
.else
PLIST_SUB+=	TRE="@comment "
.endif

.include <bsd.port.pre.mk>

# XXX Add here other arch which needs -fPIC :-)
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
.if ${PORT_OPTIONS:MGNUTLS}
	${LN} -s ${WRKSRC}/modules/extra/m_ssl_gnutls.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MLDAP}
	${LN} -s ${WRKSRC}/modules/extra/m_ldap.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_ldap_authentication.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_ldap_oper.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MMYSQL}
	${LN} -s ${WRKSRC}/modules/extra/m_mysql.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_sql_authentication.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_sql_log.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_sql_oper.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MOPENSSL}
	${LN} -s ${WRKSRC}/modules/extra/m_ssl_openssl.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MSQLITE}
	${LN} -s ${WRKSRC}/modules/extra/m_sqlite.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MPCRE}
	${LN} -s ${WRKSRC}/modules/extra/m_regex_pcre.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MPOSIX}
	${LN} -s ${WRKSRC}/modules/extra/m_regex_posix.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MSASL}
	${LN} -s ${WRKSRC}/modules/extra/m_sasl_dh-aes.cpp ${WRKSRC}/modules/
	${LN} -s ${WRKSRC}/modules/extra/m_sasl_dh-blowfish.cpp ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MSTATS}
	${LN} -s ${WRKSRC}/modules/extra/stats ${WRKSRC}/modules/
.endif
.if ${PORT_OPTIONS:MTRE}
	${LN} -s ${WRKSRC}/modules/extra/m_regex_tre.cpp ${WRKSRC}/modules/
.endif

post-install:
	${MKDIR} ${STAGEDIR}/${LOCALBASE}/anope/data/backups
	${MKDIR} ${STAGEDIR}/${LOCALBASE}/anope/logs

.include <bsd.port.post.mk>
