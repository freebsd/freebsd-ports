# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendnssec
PORTVERSION=	2.0.0
CATEGORIES=	dns
MASTER_SITES=	http://dist.opendnssec.org/source/
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ldns>=1.6.16:dns/ldns
LIB_DEPENDS=	libldns.so:dns/ldns

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir="${PREFIX}/var"
USE_RC_SUBR=	opendnssec
USE_GNOME=	libxml2
USES=		perl5
USES=		ssl
USE_LDCONFIG=	yes

SUB_FILES+=	pkg-message

CONFLICTS=	opendnssec-1.[0-4]*

USERS=		opendnssec
GROUPS=		opendnssec

PORTDOCS=	MIGRATION NEWS README.md
MIGRATE=	README.md find_problematic_zones.sql \
		convert_mysql mysql_convert.sql \
		convert_sqlite sqlite_convert.sql

OPTIONS_DEFINE=		SOFTHSM DOCS
OPTIONS_SUB=		yes

OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	SQLITE MYSQL

OPTIONS_DEFAULT=	DOCS SQLITE

SOFTHSM_DESC=		SoftHSM cryptographic store for PKCS \#11 interface

MYSQL_DESC=		Use MYSQL backend
SQLITE_DESC=		Use SQLite backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-enforcer-database=mysql
USES+=		mysql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USES=		sqlite
CONFIGURE_ARGS+=	--with-enforcer-database=sqlite3
BUILD_DEPENDS+=	sqlite3>=3.3.9:databases/sqlite3
.endif

.if ${PORT_OPTIONS:MSOFTHSM}
CONFIGURE_ARGS+=	--with-pkcs11-softhsm=${LOCALBASE}/lib/softhsm/libsofthsm.so
RUN_DEPENDS+=	softhsm>=1.2.0:security/softhsm
.endif

pre-install:
.if ${PORT_OPTIONS:MMYSQL}
	${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' ${WRKDIR}/opendnssec
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert
	${INSTALL_DATA} \
		${MIGRATE:S|^|${WRKSRC}/enforcer/utils/1.4-2.0_db_convert/|} \
		${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert
.endif

.include <bsd.port.mk>
