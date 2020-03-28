# Created by: Konstantin Saurbier <saurbier@math.uni-bielefeld.de>
# $FreeBSD$

PORTNAME=	ldns
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/ldns/ \
		LOCAL/ehaupt

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Library for programs conforming to DNS RFCs and drafts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake libtool perl5 ssl
USE_PERL5=	build
USE_LDCONFIG=	yes

CPE_VENDOR=	nlnetlabs
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-dane-ta-usage \
			--with-ssl=${OPENSSLBASE}
MAKE_JOBS_UNSAFE=	yes

.if ! (defined(BUILD_PYLDNS) || defined(BUILD_P5PERL))
OPTIONS_DEFINE=		DOXYGEN DRILL EXAMPLES
OPTIONS_DEFAULT=	DRILL

DRILL_DESC=	With drill program

.endif

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
HTMLDOCS=		doc/html/*

OPTIONS_DEFINE+=	DANETAUSAGE GOST RRTYPEAMTRELAY RRTYPEAVC RRTYPENINFO \
			RRTYPERKEY RRTYPETA

DANETAUSAGE_DESC=	Enable ta usage, requires openssl >= 1.1.0
GOST_DESC=		GOST signatures enabled, requires openssl >= 1.0.0
RRTYPENINFO_DESC=	Enable draft RR type ninfo.
RRTYPERKEY_DESC=	Enable draft RR type rkey.
RRTYPETA_DESC=		Enable draft RR type ta.
RRTYPEAVC_DESC=		Enable draft RR type avc.
RRTYPEAMTRELAY_DESC=	Enable draft RR type amtrelay.

OPTIONS_SUB=	yes

DANETAUSAGE_CONFIGURE_ENABLE=		dane-ta-usage
DANETAUSAGE_IMPLIES=			RRTYPETA
GOST_CONFIGURE_ENABLE=			gost
RRTYPENINFO_CONFIGURE_ENABLE=		rrtype-ninfo
RRTYPERKEY_CONFIGURE_ENABLE=		rrtype-rkey
RRTYPETA_CONFIGURE_ENABLE=		rrtype-ta
RRTYPEAVC_CONFIGURE_ENABLE=		rrtype-avc
RRTYPEAMTRELAY_CONFIGURE_ENABLE=	rrtype-amtrelay
EXAMPLES_CONFIGURE_WITH=		examples
DRILL_CONFIGURE_WITH=			drill
DRILL_INSTALL_TARGET=			install-drill
EXAMPLES_INSTALL_TARGET=		install-examples

.if defined(BUILD_PYLDNS)
USES+=		python
USE_PYTHON=	flavors
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
ALL_TARGET=	pyldns
INSTALL_TARGET=	install-pyldns

CONFIGURE_ARGS+=	--with-pyldns
LIB_DEPENDS+=		libldns.so:dns/ldns
BUILD_DEPENDS+=		swig3.0:devel/swig30
CFLAGS+=		-I${OPENSSLINC}
BINARY_ALIAS=		swig=swig3.0

post-patch:
	@${REINPLACE_CMD} \
		-e 's=-I./include/ldns=-I${LOCALBASE}/include/ldns=' \
		${WRKSRC}/Makefile.in
.elif defined(BUILD_P5PERL)
USES+=		perl5
USE_PERL5=	build run
PKGNAMEPREFIX=	p5-DNS-

ALL_TARGET=	p5-dns-ldns
INSTALL_TARGET=	install-p5-dns-ldns

CONFIGURE_ARGS+=	--with-p5-dns-ldns
RUN_DEPENDS=		p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
			p5-Test-Exception>=0:devel/p5-Test-Exception
BUILD_DEPENDS=		${RUN_DEPENDS}
LIB_DEPENDS+=		libldns.so:dns/ldns

post-patch:
	@${SED} -i '' -e 's=-I./include/ldns=-I${LOCALBASE}/include/ldns=' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DNS/LDNS/LDNS.so
.else
ALL_TARGET=	all
INSTALL_TARGET=	install-lib install-h install-config

.endif # BUILD_PYLDNS || BUILD_P5PERL

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDANETAUSAGE} && \
    ((${OSVERSION} < 1200084 && ${SSL_DEFAULT} == base))
BROKEN=		this option requires openssl >= 1.1.0 ${OSVERSION} ${SSL_DEFAULT}
.endif

.if ! ${PORT_OPTIONS:MGOST}
NO_GOST=	--disable-gost
.endif

.if ! (defined(BUILD_PYLDNS) || defined(BUILD_P5PERL))

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	@(cd ${WRKSRC}; ${MAKE_CMD} doxygen)
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/packaging/libldns.pc \
		 ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_MAN} ${WRKSRC}/packaging/ldns-config.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/ldns_*.3 \
		${STAGEDIR}${PREFIX}/man/man3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.3
.if ${PORT_OPTIONS:MDRILL}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/drill
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	for p in ldns-chaos ldns-compare-zones ldns-dane ldns-dpa ldns-gen-zone ldns-key2ds \
		ldns-keyfetcher ldns-keygen ldns-mx ldns-notify ldns-nsec3-hash \
		ldns-read-zone ldns-resolver ldns-revoke ldns-rrsig ldns-signzone \
		ldns-test-edns ldns-testns ldns-update ldns-verify-zone ldns-version \
		ldns-walk ldns-zcat ldns-zsplit ldnsd; do \
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$$p; done
.endif
.if ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${HTMLDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/html
.endif

.endif # BUILD_PYLDNS || BUILD_P5PERL

.include <bsd.port.post.mk>
