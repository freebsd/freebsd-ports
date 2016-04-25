# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendnssec
PORTVERSION=	1.3.18
CATEGORIES=	dns
MASTER_SITES=	http://dist.opendnssec.org/source/ \
	http://dist.opendnssec.org/source/testing/
PKGNAMESUFFIX=	13

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

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB+=	USER=${USERS} GROUP=${GROUPS}

CONFLICTS=	opendnssec-1.4*

OPTIONS_DEFINE=		SOFTHSM AUDITOR MYSQL
SOFTHSM_DESC=		SoftHSM cryptographic store for PKCS \#11 interface
AUDITOR_DESC=		Build with Auditor
OPTIONS_DEFAULT=	AUDITOR
OPTIONS_SUB=		yes

AUDITOR_BUILD_DEPENDS=	rubygem-soap4r>=0:devel/rubygem-soap4r \
			rubygem-dnsruby>=1.53:dns/rubygem-dnsruby
AUDITOR_CONFIGURE_ENABLE=	auditor
AUDITOR_USE=		RUBY=yes
MYSQL_BUILD_DEPENDS_OFF=sqlite3>=3.3.9:databases/sqlite3
MYSQL_CONFIGURE_OFF=	--with-sqlite3=${LOCALBASE} --with-database-backend=sqlite3
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE} --with-database-backend=mysql
MYSQL_LIB_DEPENDS_OFF=	libsqlite3.so:databases/sqlite3
MYSQL_USE=		MYSQL=compat
MYSQL_USES_OFF=		sqlite
SOFTHSM_CONFIGURE_ON=	--with-softhsm --with-pkcs11-softhsm=${LOCALBASE}/lib/softhsm/libsofthsm.so
SOFTHSM_RUN_DEPENDS=	softhsm>=1.2.0:security/softhsm

PKGMESSAGE=	${WRKSRC}/MIGRATION

pre-install-MYSQL-on:
	${REINPLACE_CMD} -e '/REQUIRE:/ s|$$| mysql|' ${WRKDIR}/opendnssec

.include <bsd.port.mk>
