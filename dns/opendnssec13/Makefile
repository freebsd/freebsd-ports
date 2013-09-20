# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendnssec
PORTVERSION=	1.3.14
CATEGORIES=	dns
MASTER_SITES=	http://dist.opendnssec.org/source/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC

BUILD_DEPENDS=	ldns>=1.6.16:${PORTSDIR}/dns/ldns
LIB_DEPENDS=	ldns:${PORTSDIR}/dns/ldns

LATEST_LINK=	${PORTNAME}13

GNU_CONFIGURE=	yes
USE_RC_SUBR=	opendnssec
USE_GNOME=	libxml2
USES=		perl5
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

CONFLICTS=	opendnssec-1.4*

MAN1=		ods-hsmspeed.1 ods-hsmutil.1 ods-ksmutil.1
MAN5=		ods-timing.5
MAN7=		opendnssec.7
MAN8=		ods-control.8 ods-enforcerd.8 ods-signer.8 ods-signerd.8

OPTIONS_DEFINE=		SOFTHSM AUDITOR MYSQL
SOFTHSM_DESC=		SoftHSM cryptographic store for PKCS \#11 interface
AUDITOR_DESC=		Build with Auditor
OPTIONS_DEFAULT=	AUDITOR

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_ARGS+=	--with-database-backend=mysql
USE_MYSQL=	compat
PLIST_SUB+=	SQLITE="@comment "
PLIST_SUB+=	MYSQL=""
.else
BUILD_DEPENDS+=	sqlite3>=3.3.9:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE=""
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MAUDITOR}
BUILD_DEPENDS+=	rubygem-soap4r>=0:${PORTSDIR}/devel/rubygem-soap4r
BUILD_DEPENDS+=	rubygem-dnsruby>=1.53:${PORTSDIR}/dns/rubygem-dnsruby
USE_RUBY=	yes
PLIST_SUB+=	AUDITOR=""
MAN1+=		ods-auditor.1 ods-kaspcheck.1
.else
CONFIGURE_ARGS+=	--disable-auditor
PLIST_SUB+=	AUDITOR="@comment "
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
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif
	${CHOWN} -R ${USERS}:${GROUPS} ${PREFIX}/var/opendnssec

.include <bsd.port.mk>
