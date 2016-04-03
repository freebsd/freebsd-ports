# Created by: dom
# $FreeBSD$

PORTNAME=	pcre
PORTVERSION=	8.38
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.csx.cam.ac.uk/pub/software/programming/${PORTNAME}/ \
		ftp://ftp.fu-berlin.de/unix/misc/${PORTNAME}/ \
		ftp://ftp.tin.org/pub/libs/${PORTNAME}/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

GNU_CONFIGURE=	yes
USES=		libtool pathfix tar:bzip2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-utf --enable-unicode-properties \
		--enable-pcre8 --enable-pcre16 --enable-pcre32
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS STACK_RECURSION
OPTIONS_DEFAULT=	STACK_RECURSION
OPTIONS_RADIO=	CLI
OPTIONS_RADIO_CLI=	LIBEDIT READLINE

STACK_RECURSION_DESC=	Use the stack for recursion during matching

LIBEDIT_CONFIGURE_ENABLE=	pcretest-libedit
LIBEDIT_USES=			libedit

READLINE_USES=			readline
READLINE_CONFIGURE_ENABLE=	pcretest-libreadline

.include <bsd.port.options.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "ia64" && ${ARCH:Mmips64*} == ""
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

# Adjust the default maximum number of substrings that will be stored on the stack
# when the 8-bit library is called via the POSIX interface (default: 10):
.if defined(WITH_POSIX_MALLOC_THRESHOLD)
CONFIGURE_ARGS+=	--with-posix-malloc-threshold=${WITH_POSIX_MALLOC_THRESHOLD}
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^\.rs/d" ${WRKSRC}/doc/*.3 ${WRKSRC}/doc/*.1
	@${REINPLACE_CMD} -e "s/£//g" ${WRKSRC}/doc/pcre_compile2.3
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E -e '/^install-data-am/,/^$$/ s,install-(dist_doc|dist_html|html)DATA,,g' \
		${WRKSRC}/Makefile.in
.endif

#prevent regression test coredumps from causing failures on the
#package-building cluster:
.ifndef(MAINTAINER_MODE)
CORELIMIT?=	/usr/bin/limits -Sc 0
.endif
TESTLOGS?=	RunGrepTest RunTest pcre_jit_test pcre_scanner_unittest \
		pcre_stringpiece_unittest pcrecpp_unittest

post-stage:
	${LN} -s libpcre.so.1 ${STAGEDIR}${PREFIX}/lib/libpcre.so.3

check regression-test test: build
	@cd ${WRKSRC} ; \
	${SETENV} ${MAKE_ENV} ${CORELIMIT} ${MAKE_CMD} ${MAKE_ARGS} check ; \
	for _l in ${TESTLOGS} ; do if ${TEST} -f $${_l}.log ; then \
	${PRINTF} "\n\n$${_l}.log\n\n\n" ; ${CAT} $${_l}.log ; fi ; done

.include <bsd.port.mk>
