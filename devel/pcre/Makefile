# Created by: dom
# $FreeBSD$

PORTNAME=	pcre
PORTVERSION=	8.33
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.csx.cam.ac.uk/pub/software/programming/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/misc/%SUBDIR%/ \
		ftp://ftp.tin.org/pub/libs/%SUBDIR%/
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENCE

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	pathfix
CONFIGURE_ARGS=	--enable-utf --enable-unicode-properties \
		--enable-pcre8 --enable-pcre16 --enable-pcre32

OPTIONS_DEFINE=		STACK_RECURSION
OPTIONS_DEFAULT=	STACK_RECURSION

STACK_RECURSION_DESC=	Use the stack for recursion during matching

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "ia64"
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

# For FreeBSD 8.3 and above link pcretest against libedit
.if ${OSVERSION} >= 803000
CONFIGURE_ARGS+=	--enable-pcretest-libedit
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
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

# Adjust the default maximum number of substrings that will be stored on the stack
# when the 8-bit library is called via the POSIX interface (default: 10):
.if defined(WITH_POSIX_MALLOC_THRESHOLD)
CONFIGURE_ARGS+=	--with-posix-malloc-threshold=${WITH_POSIX_MALLOC_THRESHOLD}
.endif

MAN1=		pcre-config.1 \
		pcregrep.1 \
		pcretest.1
MAN3=		pcre.3 \
		pcre16.3 \
		pcre32.3 \
		pcre_assign_jit_stack.3 \
		pcre_compile.3 \
		pcre_compile2.3 \
		pcre_config.3 \
		pcre_copy_named_substring.3 \
		pcre_copy_substring.3 \
		pcre_dfa_exec.3 \
		pcre_exec.3 \
		pcre_free_study.3 \
		pcre_free_substring.3 \
		pcre_free_substring_list.3 \
		pcre_fullinfo.3 \
		pcre_get_named_substring.3 \
		pcre_get_stringnumber.3 \
		pcre_get_stringtable_entries.3 \
		pcre_get_substring.3 \
		pcre_get_substring_list.3 \
		pcre_jit_exec.3 \
		pcre_jit_stack_alloc.3 \
		pcre_jit_stack_free.3 \
		pcre_maketables.3 \
		pcre_pattern_to_host_byte_order.3 \
		pcre_refcount.3 \
		pcre_study.3 \
		pcre_version.3 \
		pcreapi.3 \
		pcrebuild.3 \
		pcrecallout.3 \
		pcrecompat.3 \
		pcrecpp.3 \
		pcredemo.3 \
		pcrejit.3 \
		pcrelimits.3 \
		pcrematching.3 \
		pcrepartial.3 \
		pcrepattern.3 \
		pcreperform.3 \
		pcreposix.3 \
		pcreprecompile.3 \
		pcresample.3 \
		pcrestack.3 \
		pcresyntax.3 \
		pcre_utf16_to_host_byte_order.3 \
		pcre_utf32_to_host_byte_order.3 \
		pcreunicode.3

MLINKS+=	pcre_assign_jit_stack.3 pcre16_assign_jit_stack.3 \
		pcre_assign_jit_stack.3 pcre32_assign_jit_stack.3 \
		pcre_compile.3 pcre16_compile.3 \
		pcre_compile.3 pcre32_compile.3 \
		pcre_compile2.3 pcre16_compile2.3 \
		pcre_compile2.3 pcre32_compile2.3 \
		pcre_config.3 pcre16_config.3 \
		pcre_config.3 pcre32_config.3 \
		pcre_copy_named_substring.3 pcre16_copy_named_substring.3 \
		pcre_copy_named_substring.3 pcre32_copy_named_substring.3 \
		pcre_copy_substring.3 pcre16_copy_substring.3 \
		pcre_copy_substring.3 pcre32_copy_substring.3 \
		pcre_dfa_exec.3 pcre16_dfa_exec.3 \
		pcre_dfa_exec.3 pcre32_dfa_exec.3 \
		pcre_exec.3 pcre16_exec.3 \
		pcre_exec.3 pcre32_exec.3 \
		pcre_free_study.3 pcre16_free_study.3 \
		pcre_free_study.3 pcre32_free_study.3 \
		pcre_free_substring.3 pcre16_free_substring.3 \
		pcre_free_substring.3 pcre32_free_substring.3 \
		pcre_free_substring_list.3 pcre16_free_substring_list.3 \
		pcre_free_substring_list.3 pcre32_free_substring_list.3 \
		pcre_fullinfo.3 pcre16_fullinfo.3 \
		pcre_fullinfo.3 pcre32_fullinfo.3 \
		pcre_get_named_substring.3 pcre16_get_named_substring.3 \
		pcre_get_named_substring.3 pcre32_get_named_substring.3 \
		pcre_get_stringnumber.3 pcre16_get_stringnumber.3 \
		pcre_get_stringnumber.3 pcre32_get_stringnumber.3 \
		pcre_get_stringtable_entries.3 pcre16_get_stringtable_entries.3 \
		pcre_get_stringtable_entries.3 pcre32_get_stringtable_entries.3 \
		pcre_get_substring.3 pcre16_get_substring.3 \
		pcre_get_substring.3 pcre32_get_substring.3 \
		pcre_get_substring_list.3 pcre16_get_substring_list.3 \
		pcre_get_substring_list.3 pcre32_get_substring_list.3 \
		pcre_jit_exec.3 pcre16_jit_exec.3 \
		pcre_jit_exec.3 pcre32_jit_exec.3 \
		pcre_jit_stack_alloc.3 pcre16_jit_stack_alloc.3 \
		pcre_jit_stack_alloc.3 pcre32_jit_stack_alloc.3 \
		pcre_jit_stack_free.3 pcre16_jit_stack_free.3 \
		pcre_jit_stack_free.3 pcre32_jit_stack_free.3 \
		pcre_maketables.3 pcre16_maketables.3 \
		pcre_maketables.3 pcre32_maketables.3 \
		pcre_pattern_to_host_byte_order.3 pcre16_pattern_to_host_byte_order.3 \
		pcre_pattern_to_host_byte_order.3 pcre32_pattern_to_host_byte_order.3 \
		pcre_refcount.3 pcre16_refcount.3 \
		pcre_refcount.3 pcre32_refcount.3 \
		pcre_study.3 pcre16_study.3 \
		pcre_study.3 pcre32_study.3 \
		pcre_utf16_to_host_byte_order.3 pcre16_utf16_to_host_byte_order.3 \
		pcre_utf16_to_host_byte_order.3 pcre32_utf16_to_host_byte_order.3 \
		pcre_utf32_to_host_byte_order.3 pcre32_utf32_to_host_byte_order.3 \
		pcre_version.3 pcre16_version.3 \
		pcre_version.3 pcre32_version.3

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E -e '/^install-data-am/,/^$$/ s,install-(dist_doc|dist_html|html)DATA,,g' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's/\(pkgconfigdir = \).*/\1$$\(DESTDIR\)$$\(prefix\)\/libdata\/pkgconfig/' \
		${WRKSRC}/Makefile.in
# work around for a autoconf assumption, to fix c++ linking with clang
	@${REINPLACE_CMD} -e 's|GREP "\\-L"|GREP "conftest\\.$$objext"|g' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pcregrep ${PREFIX}/bin/pcretest

#prevent regression test coredumps from causing failures on the
#package-building cluster:
.ifndef(MAINTAINER_MODE)
CORELIMIT?=	/usr/bin/limits -Sc 0
.endif
TESTLOGS?=	RunGrepTest RunTest pcre_jit_test pcre_scanner_unittest \
		pcre_stringpiece_unittest pcrecpp_unittest

check regression-test test: build
	@cd ${WRKSRC} ; \
	${SETENV} ${MAKE_ENV} ${CORELIMIT} ${MAKE} ${MAKE_ARGS} check ; \
	for _l in ${TESTLOGS} ; do if ${TEST} -f $${_l}.log ; then \
	${PRINTF} "\n\n$${_l}.log\n\n\n" ; ${CAT} $${_l}.log ; fi ; done

.include <bsd.port.mk>
