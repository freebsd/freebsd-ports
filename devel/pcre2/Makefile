PORTNAME=	pcre2
PORTVERSION=	10.42
CATEGORIES=	devel
MASTER_SITES=	https://github.com/PCRE2Project/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions library, version 2
WWW=		https://www.pcre.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		autoreconf cpe libtool pkgconfig tar:bz2
CPE_VENDOR=	pcre

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pcre2-16 \
		--enable-pcre2-32
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS LIBBZ2 LIBZ
OPTIONS_RADIO=		CLI
OPTIONS_RADIO_CLI=	LIBEDIT READLINE

LIBBZ2_DESC=	Using pcre2grep with .bz2 files
LIBZ_DESC=	Using pcre2grep with .gz files

LIBBZ2_CONFIGURE_ON=	--enable-pcre2grep-libbz2
LIBEDIT_USES=			libedit
LIBEDIT_CONFIGURE_ENABLE=	pcre2test-libedit
LIBZ_CONFIGURE_ON=	--enable-pcre2grep-libz
READLINE_USES=			readline
READLINE_CONFIGURE_ENABLE=	pcre2test-libreadline

.include <bsd.port.options.mk>

.if ${ARCH:Mmips64*} == "" && ${ARCH:Mriscv64*} == ""
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

# Optional knobs that accept positive integer parameters (see pcrebuild(3)):

# Allow the use of very large patterns (> 64K) with the 8- and 16-bit
# libraries, at the expense of longer load times (possible values:
# 2 (default), 3, and 4):
.if defined(WITH_LINK_SIZE)
CONFIGURE_ARGS+=	--with-link-size=${WITH_LINK_SIZE}
.endif

# Control PCRE resource use by limiting the default number of times pcre_exec()
# can call match() during a single operation (default: 10 million):
.if defined(WITH_MATCH_LIMIT)
CONFIGURE_ARGS+=	--with-match-limit=${WITH_MATCH_LIMIT}
.endif

# Control PCRE resource use by limiting the nesting depth of parentheses in
# patterns compiled with pcre_compile() (default: 250):
.if defined(WITH_PARENS_NEST_LIMIT)
CONFIGURE_ARGS+=	--with-parens-nest-limit=${WITH_PARENS_NEST_LIMIT}
.endif

#prevent regression test coredumps from causing failures on the
#package-building cluster:
.ifndef(MAINTAINER_MODE)
CORELIMIT?=	/usr/bin/limits -Sc 0
.endif
TESTLOGS?=	RunGrepTest RunTest pcre_jit_test pcre_scanner_unittest \
		pcre_stringpiece_unittest pcrecpp_unittest

do-test:
	@cd ${WRKSRC} ; \
	${SETENV} ${MAKE_ENV} ${CORELIMIT} ${MAKE_CMD} ${MAKE_ARGS} check ; \
	for _l in ${TESTLOGS} ; do if ${TEST} -f $${_l}.log ; then \
	${PRINTF} "\n\n$${_l}.log\n\n\n" ; ${CAT} $${_l}.log ; fi ; done

.include <bsd.port.mk>
