# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendnssec
PORTVERSION=	1.4.10
CATEGORIES=	dns
MASTER_SITES=	http://dist.opendnssec.org/source/

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
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CONFLICTS=	opendnssec-1.[0-3]*

USERS=		opendnssec
GROUPS=		opendnssec

PORTDOCS=	KNOWN_ISSUES MIGRATION NEWS README.md

OPTIONS_DEFINE=		SOFTHSM DOCS
OPTIONS_SUB=		yes

OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL SQLITE
OPTIONS_DEFAULT=	MYSQL

SOFTHSM_DESC=		SoftHSM cryptographic store for PKCS \#11 interface

MYSQL_DESC=		Use MYSQL backend
SQLITE_DESC=		Use SQLite backend

SQLITE_USE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-database-backend=mysql
USES+=		mysql
SCRIPTDATA=	migrate_adapters_1.mysql migrate_keyshare_mysql.pl \
		migrate_zone_delete.mysql migrate_id_mysql.pl \
		migrate_to_ng_mysql.pl migrate_1_4_8.mysql
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
CONFIGURE_ARGS+=	--with-database-backend=sqlite3
BUILD_DEPENDS+=	sqlite3>=3.3.9:databases/sqlite3
SCRIPTDATA=	database_create.sqlite3 migrate_keyshare_sqlite3.pl \
		migrate_adapters_1.sqlite3 migrate_to_ng_sqlite.pl \
		migrate_1_4_8.sqlite3
.endif

.if ${PORT_OPTIONS:MSOFTHSM}
CONFIGURE_ARGS+=	--with-pkcs11-softhsm=${LOCALBASE}/lib/softhsm/libsofthsm.so
RUN_DEPENDS+=	softhsm>=1.2.0:security/softhsm
.endif

SCRIPTDATA+=	convert_database.pl

PKGMESSAGE=	${WRKSRC}/MIGRATION

pre-install:
.if ${PORT_OPTIONS:MMYSQL}
	@${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' ${WRKDIR}/opendnssec
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_DATA} ${SCRIPTDATA:S|^|${WRKSRC}/enforcer/utils/|} ${STAGEDIR}${DATADIR}
#	${CHOWN} -R ${USERS}:${GROUPS} ${PREFIX}/var/opendnssec

.include <bsd.port.mk>
