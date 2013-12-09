# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendnssec
PORTVERSION=	1.4.3
CATEGORIES=	dns
MASTER_SITES=	http://dist.opendnssec.org/source/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC

LICENSE=	BSD

BUILD_DEPENDS=	ldns>=1.6.16:${PORTSDIR}/dns/ldns
LIB_DEPENDS=	libldns.so:${PORTSDIR}/dns/ldns

GNU_CONFIGURE=	yes
USE_RC_SUBR=	opendnssec
USE_GNOME=	libxml2
USES=		perl5
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CONFLICTS=	opendnssec-1.[0-3]*

USERS=		opendnssec
GROUPS=		opendnssec

MAN1=		ods-hsmspeed.1 ods-hsmutil.1 ods-ksmutil.1 ods-kaspcheck.1
MAN5=		ods-timing.5
MAN7=		opendnssec.7
MAN8=		ods-control.8 ods-enforcerd.8 ods-signer.8 ods-signerd.8

PORTDOCS=	KNOWN_ISSUES MIGRATION NEWS README

OPTIONS_DEFINE=		SOFTHSM MYSQL
SOFTHSM_DESC=		SoftHSM cryptographic store for PKCS \#11 interface
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_ARGS+=	--with-database-backend=mysql
USE_MYSQL=	compat
PLIST_SUB+=	SQLITE="@comment "
PLIST_SUB+=	MYSQL=""
PORTDATA=	migrate_adapters_1.mysql migrate_keyshare_mysql.pl \
		migrate_zone_delete.mysql migrate_id_mysql.pl migrate_to_ng_mysql.pl
.else
CONFIGURE_ARGS+=--with-sqlite3=${LOCALBASE}
BUILD_DEPENDS+=	sqlite3>=3.3.9:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE=""
PLIST_SUB+=	MYSQL="@comment "
PORTDATA=	database_create.sqlite3 migrate_keyshare_sqlite3.pl \
		migrate_adapters_1.sqlite3 migrate_to_ng_sqlite.pl
.endif

.if ${PORT_OPTIONS:MSOFTHSM}
CONFIGURE_ARGS+=	--with-softhsm
CONFIGURE_ARGS+=	--with-pkcs11-softhsm=${LOCALBASE}/lib/libsofthsm.so
RUN_DEPENDS+=	softhsm>=1.2.0:${PORTSDIR}/security/softhsm
.endif

PKGMESSAGE=	${WRKSRC}/MIGRATION

pre-install:
.if ${PORT_OPTIONS:MMYSQL}
	@${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' ${WRKDIR}/opendnssec
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif
	${INSTALL_DATA} ${PORTDATA:S|^|${WRKSRC}/enforcer/utils/|} ${DATADIR}
	${CHOWN} -R ${USERS}:${GROUPS} ${PREFIX}/var/opendnssec

.include <bsd.port.mk>
