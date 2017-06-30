# Created by: mat
# $FreeBSD$

PORTNAME=	anope
PORTVERSION=	2.0.5
PORTREVISION=	0
CATEGORIES=	irc

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Set of IRC services for IRC networks

LICENSE=	GPLv2

USES=		cmake:outsource shebangfix
CMAKE_ARGS+=	-DINSTDIR:STRING="${LOCALBASE}/anope"
CXXFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
SHEBANG_FILES=	${WRKSRC}/src/tools/*.sh

CFLAGS_amd64=	-fPIC

USE_GITHUB=	yes

USE_RC_SUBR=	anope

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GNUTLS LDAP MYSQL NLS OPENSSL PCRE POSIX REDIS SASL SQLITE STATS TRE
OPTIONS_DEFAULT=	MYSQL OPENSSL POSIX
OPTIONS_SUB=	yes
POSIX_DESC=	POSIX Regex Module
STATS_DESC=	Channel Statistics Module
TRE_DESC=	Tre Regex Module

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

LDAP_VARS_ON=	USE_OPENLDAP=yes

MYSQL_USES=	mysql

NLS_USES=	gettext

OPENSSL_USES=	ssl

REDIS_RUN_DEPENDS=	redis:databases/redis

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

SQLITE_USES=	sqlite

TRE_LIB_DEPENDS=	libtre.so:textproc/libtre

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

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
