# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcre2
PORTVERSION=	10.34
CATEGORIES=	devel
MASTER_SITES=	SF/pcre/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/ \
		ftp://ftp.fu-berlin.de/unix/misc/pcre/ \
		ftp://ftp.tin.org/pub/libs/pcre/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions library, version 2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		autoreconf libtool pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-pcre2-16 --enable-pcre2-32

OPTIONS_DEFINE=	DOCS STACK_RECURSION
OPTIONS_DEFAULT=	STACK_RECURSION
OPTIONS_RADIO=	CLI
OPTIONS_RADIO_CLI=	LIBEDIT READLINE

STACK_RECURSION_DESC=	Use the stack for recursion during matching

LIBEDIT_CONFIGURE_ENABLE=	pcre2test-libedit
LIBEDIT_USES=			libedit

READLINE_USES=			readline
READLINE_CONFIGURE_ENABLE=	pcre2test-libreadline

.include <bsd.port.options.mk>

.if ${ARCH} != "sparc64" && ${ARCH:Mmips64*} == ""
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

# Using the heap rather than the stack for recursion is slower but less
# prone to segfaults from stack exhaustion when matching certain patterns
.if !${PORT_OPTIONS:MSTACK_RECURSION}
CONFIGURE_ARGS+=	--disable-stack-for-recursion
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

# Control PCRE resource use by limiting the default number of times pcre_exec()
# can call match() recursively during a single operation (default: 10 million):
.if defined(WITH_MATCH_LIMIT_RECURSION)
CONFIGURE_ARGS+=	--with-match-limit-recursion=${WITH_MATCH_LIMIT_RECURSION}
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
