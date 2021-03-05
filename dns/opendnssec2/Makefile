# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendnssec
PORTVERSION=	2.1.8
CATEGORIES=	dns
MASTER_SITES=	http://dist.opendnssec.org/source/
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ldns>=1.6.16:dns/ldns
LIB_DEPENDS=	libldns.so:dns/ldns \
		libxml2.so:textproc/libxml2

USES=		ssl gmake
USE_RC_SUBR=	opendnssec

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir="${PREFIX}/var" \
		--with-ssl=${OPENSSLBASE}

SUB_FILES=	pkg-message

CONFLICTS=	opendnssec-1.[0-4]*

USERS=		opendnssec
GROUPS=		opendnssec

PORTDOCS=	MIGRATION NEWS README.md
MIGRATE=	README.md find_problematic_zones.sql \
		convert_mysql mysql_convert.sql \
		convert_sqlite sqlite_convert.sql
CONVERT=	convert_mysql_to_sqlite convert_sqlite_to_mysql
SCHEMAS=	schema.mysql schema.sqlite

OPTIONS_DEFINE=		SOFTHSM DOCS
OPTIONS_DEFAULT=	SQLITE
OPTIONS_SUB=		yes

OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	SQLITE MYSQL

SOFTHSM_DESC=		SoftHSM cryptographic store for PKCS \#11 interface

MYSQL_DESC=		Use MYSQL backend
SQLITE_DESC=		Use SQLite backend

MYSQL_CONFIGURE_ON=	--with-enforcer-database=mysql
MYSQL_USES=		mysql

SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-enforcer-database=sqlite3
SQLITE_BUILD_DEPENDS=	sqlite3>=3.3.9:databases/sqlite3

SOFTHSM_CONFIGURE_ON=	--with-pkcs11-softhsm=${LOCALBASE}/lib/softhsm/libsofthsm2.so
SOFTHSM_RUN_DEPENDS=	softhsm2>=2.5.0:security/softhsm2

INSTALL_TARGET=		install-strip

pre-build:
	${REINPLACE_CMD} -e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		${WRKSRC}/configure

pre-install-MYSQL-on:
	${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' ${WRKDIR}/opendnssec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert
	${INSTALL_DATA} \
		${MIGRATE:S|^|${WRKSRC}/enforcer/utils/1.4-2.0_db_convert/|} \
		${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert
	${INSTALL_DATA} \
		${CONVERT:S|^|${WRKSRC}/enforcer/utils/|} \
		${STAGEDIR}${DOCSDIR}
	${REINPLACE_CMD} -e 's|enforcer/utils/|${DOCSDIR}/|' \
		${STAGEDIR}${DOCSDIR}/MIGRATION
	${INSTALL_DATA} \
		${SCHEMAS:S|^|${WRKSRC}/enforcer/src/db/|} \
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
