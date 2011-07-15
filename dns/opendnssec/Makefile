# New ports collection makefile for:   opendnssec
# Date created:        28 December 2009
# Whom:                Jaap Akkerhuis <jaap@NLnetLabs.nl>
#
# $FreeBSD$
#

PORTNAME=	opendnssec
PORTVERSION=	1.3.0
CATEGORIES=	dns
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC

BUILD_DEPENDS=	ldns>=1.6.9:${PORTSDIR}/dns/ldns \
		rubygem-dnsruby>=1.52:${PORTSDIR}/dns/rubygem-dnsruby
LIB_DEPENDS=	ldns:${PORTSDIR}/dns/ldns

GNU_CONFIGURE=	yes
USE_RC_SUBR=	opendnssec
USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_PERL5=	yes
USE_RUBY=	yes
USE_LDCONFIG=	yes

MAN1=		ods-auditor.1 ods-hsmspeed.1 ods-hsmutil.1 ods-kaspcheck.1 \
		ods-ksmutil.1
MAN5=		ods-timing.5
MAN7=		opendnssec.7
MAN8=		ods-control.8 ods-enforcerd.8 ods-signer.8 ods-signerd.8

OPTIONS=	SOFTHSM "Build/update SOFTHSM as well." Off \
		MYSQL "Use with (experimental) MYSQL support" Off

.include <bsd.port.options.mk>

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_ARGS+=	--with-database-backend=mysql
BUILD_DEPENDS+=	mysql-client>=5.0.3:${PORTSDIR}/databases/mysql50-client
PLIST_SUB+=	SQLITE="@comment "
PLIST_SUB+=	MYSQL=""
.else
BUILD_DEPENDS+=	sqlite3>=3.3.9:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE=""
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_SOFTHSM)
CONFIGURE_ARGS+=	--with-softhsm
CONFIGURE_ARGS+=	--with-pkcs11-softhsm=${LOCALBASE}/lib/libsofthsm.so
RUN_DEPENDS+=	softhsm>=1.2.0:${PORTSDIR}/security/softhsm
.endif

PKGMESSAGE=	${WRKSRC}/MIGRATION

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
