# New ports collection makefile for:	pcre
# Date created:				08 July 1998
# Whom:					dom
#
# $FreeBSD$
#

PORTNAME=	pcre
PORTVERSION=	8.20
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/misc/%SUBDIR%/ \
		ftp://ftp.tin.org/pub/libs/%SUBDIR%/
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENCE

OPTIONS=	JIT "Enable Just-In-Time compiling support" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-utf8 --enable-unicode-properties

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_JIT)
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if defined(WITH_LINK_SIZE)
CONFIGURE_ARGS+=--with-link-size=${WITH_LINK_SIZE}
.endif

MAN1=		pcre-config.1 pcregrep.1 pcretest.1
MAN3=		pcre.3 pcre_assign_jit_stack.3 pcre_compile.3 \
		pcre_compile2.3 pcre_config.3 pcre_copy_named_substring.3 \
		pcre_copy_substring.3 pcre_dfa_exec.3 pcre_exec.3 \
		pcre_free_study.3 pcre_free_substring.3 \
		pcre_free_substring_list.3 pcre_fullinfo.3 \
		pcre_get_named_substring.3 pcre_get_stringnumber.3 \
		pcre_get_stringtable_entries.3 pcre_get_substring.3 \
		pcre_get_substring_list.3 pcre_info.3 \
		pcre_jit_stack_alloc.3 pcre_jit_stack_free.3 \
		pcre_maketables.3 pcrepartial.3 pcreprecompile.3 \
		pcre_refcount.3 pcre_study.3 pcre_version.3 pcreapi.3 \
		pcrebuild.3 pcrecallout.3 pcrecompat.3 \
		pcrecpp.3 pcrejit.3 pcrelimits.3 pcrematching.3 \
		pcrepattern.3 pcreperform.3 pcreposix.3 pcresample.3 \
		pcrestack.3 pcresyntax.3 pcreunicode.3

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e '/^install-data-am/,/^$$/ s,install-(dist_doc|dist_html|html)DATA,,g' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's/\(pkgconfigdir = \).*/\1$$\(DESTDIR\)$$\(prefix\)\/libdata\/pkgconfig/' \
		${WRKSRC}/Makefile.in
# work around for a autoconf assumption, to fix c++ linking with clang
	@${REINPLACE_CMD} -e 's|GREP "\\-L"|GREP "conftest\\.$$objext"|g' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pcregrep ${PREFIX}/bin/pcretest

test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} test

regression-test: test

.include <bsd.port.post.mk>
