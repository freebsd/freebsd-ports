# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendnssec
PORTVERSION=	2.0.1
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


MYSQL_CONFIGURE_ON=	--with-enforcer-database=mysql
MYSQL_USES=		mysql
 
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-enforcer-database=sqlite3
SQLITE_BUILD_DEPENDS=	sqlite3>=3.3.9:databases/sqlite3


SOFTHSM_CONFIGURE_ON=	--with-pkcs11-softhsm=${LOCALBASE}/lib/softhsm/libsofthsm.so
SOFTHSM_RUN_DEPENDS=	softhsm>=1.2.0:security/softhsm

pre-install-MYSQL-on:
	${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' ${WRKDIR}/opendnssec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert
	${INSTALL_DATA} \
		${MIGRATE:S|^|${WRKSRC}/enforcer/utils/1.4-2.0_db_convert/|} \
		${STAGEDIR}${DOCSDIR}/1.4-2.0_db_convert

.include <bsd.port.mk>
