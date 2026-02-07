PORTNAME=	opendnssec
DISTVERSION=	2.1.14
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://dist.opendnssec.org/source/
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC
WWW=		https://www.opendnssec.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ldns>=1.6.16:dns/ldns
LIB_DEPENDS=	libldns.so:dns/ldns

USES=		autoreconf cpe gnome libtool ssl
USE_GNOME=	libxml2

USE_RC_SUBR=	opendnssec

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir="${PREFIX}/var" \
		--with-ssl=${OPENSSLBASE}

INSTALL_TARGET=	install-strip

CONFLICTS=	opendnssec-1.[0-4]*

SUB_FILES=	pkg-message

USERS=		opendnssec
GROUPS=		opendnssec

PORTDOCS=	MIGRATION NEWS README.md
MIGRATE=	README.md find_problematic_zones.sql convert_mysql \
		mysql_convert.sql convert_sqlite sqlite_convert.sql
CONVERT=	convert_mysql_to_sqlite convert_sqlite_to_mysql
SCHEMAS=	schema.mysql schema.sqlite

OPTIONS_DEFINE=		DOCS SOFTHSM
OPTIONS_DEFAULT=	SQLITE
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL SQLITE
OPTIONS_SUB=		yes

MYSQL_DESC=	Use MYSQL backend
SOFTHSM_DESC=	SoftHSM cryptographic store for PKCS \#11 interface
SQLITE_DESC=	Use SQLite backend

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-enforcer-database=mysql
MYSQL_VARS=		IGNORE_WITH_MYSQL="80 81"
SOFTHSM_RUN_DEPENDS=	softhsm2>=2.5.0:security/softhsm2
SOFTHSM_CONFIGURE_ON=	--with-pkcs11-softhsm=${LOCALBASE}/lib/softhsm/libsofthsm2.so
SQLITE_BUILD_DEPENDS=	sqlite3>=3.3.9:databases/sqlite3
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-enforcer-database=sqlite3

pre-build:
	${REINPLACE_CMD} -e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		${WRKSRC}/configure

pre-install-MYSQL-on:
	${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' \
		${WRKDIR}/opendnssec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert
	${INSTALL_DATA} ${MIGRATE:S|^|${WRKSRC}/enforcer/utils/1.4-2.0_db_convert/|} \
		${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert
	${INSTALL_DATA} ${CONVERT:S|^|${WRKSRC}/enforcer/utils/|} \
		${STAGEDIR}${DOCSDIR}
	${REINPLACE_CMD} -e 's|enforcer/utils/|${DOCSDIR}/|' \
		${STAGEDIR}${DOCSDIR}/MIGRATION
	${INSTALL_DATA} ${SCHEMAS:S|^|${WRKSRC}/enforcer/src/db/|} \
		${STAGEDIR}${DOCSDIR}
	${REINPLACE_CMD} -e 's|../src/db/schema|${DOCSDIR}/schema|' \
		-e 's|mysql_convert.sql|${DOCSDIR}/1.4-2.0_db_convert/&|' \
		-e 's|sqlite_convert.sql|${DOCSDIR}/1.4-2.0_db_convert/&|' \
		-e 's|find_problematic_zones.sql|${DOCSDIR}/1.4-2.0_db_convert/&|' \
		${STAGEDIR}${DOCSDIR}/convert_*
	${REINPLACE_CMD} -e 's|../../src/db/schema|${DOCSDIR}/schema|' \
		-e 's|mysql_convert.sql|${DOCSDIR}/1.4-2.0_db_convert/&|' \
		-e 's|sqlite_convert.sql|${DOCSDIR}/1.4-2.0_db_convert/&|' \
		-e 's|find_problematic_zones.sql|${DOCSDIR}/1.4-2.0_db_convert/&|' \
		${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert/convert_*

.include <bsd.port.mk>
