PORTNAME=	ldns
DISTVERSION=	1.9.0
CATEGORIES=	dns
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/ldns/ \
		LOCAL/ehaupt

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Library for programs conforming to DNS RFCs and drafts
WWW=		https://www.nlnetlabs.nl/projects/ldns/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake libtool perl5 ssl
CPE_VENDOR=	nlnetlabs
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-dane-ta-usage \
			--with-ssl=${OPENSSLBASE}
MAKE_JOBS_UNSAFE=	yes

.if ! (defined(BUILD_PYLDNS) || defined(BUILD_P5PERL))
OPTIONS_DEFINE=		DOXYGEN DRILL EXAMPLES
OPTIONS_DEFAULT=	DRILL
.endif

OPTIONS_DEFINE+=	DANETAUSAGE GOST RRTYPEAMTRELAY RRTYPEAVC RRTYPENINFO \
			RRTYPERKEY RRTYPETA

OPTIONS_SUB=		yes

DANETAUSAGE_DESC=	Enable ta usage, requires openssl >= 1.1.0
DRILL_DESC=		With drill program
GOST_DESC=		GOST signatures enabled, requires openssl >= 1.0.0
RRTYPEAMTRELAY_DESC=	Enable draft RR type amtrelay.
RRTYPEAVC_DESC=		Enable draft RR type avc.
RRTYPENINFO_DESC=	Enable draft RR type ninfo.
RRTYPERKEY_DESC=	Enable draft RR type rkey.
RRTYPETA_DESC=		Enable draft RR type ta.

DANETAUSAGE_IMPLIES=			RRTYPETA
DANETAUSAGE_CONFIGURE_ENABLE=		dane-ta-usage
DOXYGEN_BUILD_DEPENDS=			doxygen:devel/doxygen
DRILL_CONFIGURE_WITH=			drill
DRILL_INSTALL_TARGET=			install-drill
EXAMPLES_CONFIGURE_WITH=		examples
EXAMPLES_INSTALL_TARGET=		install-examples
GOST_CONFIGURE_ENABLE=			gost
RRTYPEAMTRELAY_CONFIGURE_ENABLE=	rrtype-amtrelay
RRTYPEAVC_CONFIGURE_ENABLE=		rrtype-avc
RRTYPENINFO_CONFIGURE_ENABLE=		rrtype-ninfo
RRTYPERKEY_CONFIGURE_ENABLE=		rrtype-rkey
RRTYPETA_CONFIGURE_ENABLE=		rrtype-ta

.if defined(BUILD_PYLDNS)

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
BUILD_DEPENDS+=	swig:devel/swig
LIB_DEPENDS+=	libldns.so:dns/ldns
USES+=		python
USE_PYTHON=	flavors

CONFIGURE_ARGS+=	--with-pyldns

ALL_TARGET=	pyldns
INSTALL_TARGET=	install-pyldns
CFLAGS+=	-I${OPENSSLINC}

post-patch:
	@${REINPLACE_CMD} \
		-e 's=-I./include/ldns=-I${LOCALBASE}/include/ldns=' \
		${WRKSRC}/Makefile.in
post-install:
# file /usr/local/lib/python3.11/site-packages/_ldns.so.3.6.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}/site-packages/_ldns.so.3.6.0

.elif defined(BUILD_P5PERL)

PKGNAMEPREFIX=	p5-DNS-
_BR_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		p5-Test-Exception>=0:devel/p5-Test-Exception
BUILD_DEPENDS=	${_BR_DEPENDS}
LIB_DEPENDS+=	libldns.so:dns/ldns
RUN_DEPENDS=	${_BR_DEPENDS}
USES+=		perl5
USE_PERL5=	build run

CONFIGURE_ARGS+=	--with-p5-dns-ldns

ALL_TARGET=	p5-dns-ldns
INSTALL_TARGET=	install-p5-dns-ldns

post-patch:
	@${REINPLACE_CMD} \
		-e 's=-I./include/ldns=-I${LOCALBASE}/include/ldns=' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DNS/LDNS/LDNS.so

.else # BUILD_PYLDNS || BUILD_P5PERL

ALL_TARGET=	all
INSTALL_TARGET=	install-lib install-h install-config

EXAMPLES_LIST=	ldns-chaos ldns-compare-zones ldns-dane ldns-dpa ldns-gen-zone ldns-key2ds \
		ldns-keyfetcher ldns-keygen ldns-mx ldns-notify ldns-nsec3-hash \
		ldns-read-zone ldns-resolver ldns-revoke ldns-rrsig ldns-signzone \
		ldns-test-edns ldns-testns ldns-update ldns-verify-zone ldns-version \
		ldns-walk ldns-zcat ldns-zsplit ldnsd

post-build-DOXYGEN-on:
	@(cd ${WRKSRC}; ${MAKE_CMD} doxygen)

post-install:
	${INSTALL_DATA} ${WRKSRC}/packaging/libldns.pc \
		 ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_MAN} ${WRKSRC}/packaging/ldns-config.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/ldns_*.3 \
		${STAGEDIR}${PREFIX}/share/man/man3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.3

post-install-DOXYGEN-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

post-install-DRILL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/drill

post-install-EXAMPLES-on:
	${STRIP_CMD} ${EXAMPLES_LIST:S|^|${STAGEDIR}${PREFIX}/bin/|}

.endif # BUILD_PYLDNS || BUILD_P5PERL

.include <bsd.port.mk>
