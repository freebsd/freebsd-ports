# Created by: Konstantin Saurbier <saurbier@math.uni-bielefeld.de>
# $FreeBSD$

PORTNAME=	ldns
PORTVERSION=	1.6.17
PORTREVISION=	5
CATEGORIES=	dns
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/ \
		LOCAL/ehaupt

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Library for programs conforming to DNS RFCs and drafts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		cpe gmake libtool
CPE_VENDOR=	nlnetlabs
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

.if ! (defined(BUILD_PYLDNS) || defined(BUILD_P5PERL))
OPTIONS_DEFINE=	DOXYGEN EXAMPLES DRILL
OPTIONS_DEFAULT=	DRILL

DRILL_DESC=	With drill program
.endif

OPTIONS_DEFINE+=	GOST \
		RRTYPENINFO RRTYPERKEY RRTYPECDS RRTYPEURI RRTYPETA

GOST_DESC=	GOST signatures enabled, requires openssl >= 1.0.0
RRTYPENINFO_DESC=	Enable draft RR type ninfo.
RRTYPERKEY_DESC=	Enable draft RR type rkey.
RRTYPECDS_DESC=		Enable draft RR type cds.
RRTYPEURI_DESC=		Enable draft RR type uri.
RRTYPETA_DESC=		Enable draft RR type ta.

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if defined(BUILD_PYLDNS)
USES+=		python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
ALL_TARGET=	pyldns
INSTALL_TARGET=	install-pyldns

CONFIGURE_ARGS+=--with-pyldns
LIB_DEPENDS+=	libldns.so:dns/ldns
BUILD_DEPENDS+=	${LOCALBASE}/bin/swig:devel/swig13

post-patch:
	@${SED} -i '' -e 's=-I./include/ldns=-I${LOCALBASE}/include/ldns=' ${WRKSRC}/Makefile.in
.elif defined(BUILD_P5PERL)
USES+=		perl5
USE_PERL5=	build run
PKGNAMEPREFIX=	p5-DNS-

ALL_TARGET=	p5-dns-ldns
INSTALL_TARGET=	install-p5-dns-ldns

CONFIGURE_ARGS+=--with-p5-dns-ldns
LIB_DEPENDS+=	libldns.so:dns/ldns

post-patch:
	@${SED} -i '' -e 's=-I./include/ldns=-I${LOCALBASE}/include/ldns=' ${WRKSRC}/Makefile.in
.else
ALL_TARGET=	all
INSTALL_TARGET=	install-lib install-h install-config

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:devel/doxygen
ALL_TARGET+=	doc
INSTALL_TARGET+=install-manpages
.endif

.endif # BUILD_PYLDNS || BUILD_P5PERL

.if ${PORT_OPTIONS:MGOST}
. if ${OSVERSION} < 1000015
BUILD_DEPENDS+=	openssl>=1.0:security/openssl
CONFLICTS+=	libressl-*
. endif
.else
NO_GOST=	--disable-gost
CONFIGURE_ARGS+=${NO_GOST}
.endif

.if ${PORT_OPTIONS:MRRTYPENINFO}
CONFIGURE_ARGS+=	--enable-rrtype-ninfo
.endif

.if ${PORT_OPTIONS:MRRTYPERKEY}
CONFIGURE_ARGS+=	--enable-rrtype-rkey
.endif

.if ${PORT_OPTIONS:MRRTYPECDS}
CONFIGURE_ARGS+=	--enable-rrtype-cds
.endif

.if ${PORT_OPTIONS:MRRTYPEURI}
CONFIGURE_ARGS+=	--enable-rrtype-uri
.endif

.if ${PORT_OPTIONS:MRRTYPETA}
CONFIGURE_ARGS+=	--enable-rrtype-ta
.endif

.if ! (defined(BUILD_PYLDNS) || defined(BUILD_P5PERL))

post-configure:
# ac_cv_prog_libtool=../libtool => Always use bundled libtool
.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples; ./configure --prefix=${PREFIX} \
		--infodir=${PREFIX}/${INFO_PATH} --mandir=${MANPREFIX}/man \
		--build=${CONFIGURE_TARGET} ${NO_GOST} ${NO_SHA2} \
		ac_cv_prog_libtool=../libtool)
.endif
.if ${PORT_OPTIONS:MDRILL}
	@(cd ${WRKSRC}/drill; ./configure --prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man \
		--build=${CONFIGURE_TARGET} \
		ac_cv_prog_libtool=../libtool)
.endif

post-build:
.if ${PORT_OPTIONS:MEXAMPLES}
	 @(cd ${WRKSRC}/examples; ${MAKE_CMD})
.endif
.if ${PORT_OPTIONS:MDRILL}
	 @(cd ${WRKSRC}/drill; ${MAKE_CMD})
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples; ${MAKE_CMD} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MDRILL}
	@(cd ${WRKSRC}/drill; ${MAKE_CMD} ${MAKE_ARGS} install)
.endif
	${INSTALL_DATA} ${WRKSRC}/packaging/libldns.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.endif # BUILD_PYLDNS || BUILD_P5PERL

.include <bsd.port.mk>
