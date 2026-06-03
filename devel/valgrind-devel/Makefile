PORTNAME=	valgrind
DISTVERSIONPREFIX=	freebsd-
DISTVERSION=	3.26.0.g20250819
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://snapshots.sourceware.org/valgrind/trunk/2025-08-18_19-19_1755544741/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION:R}.GIT

MAINTAINER=	pjfloyd@wanadoo.fr
COMMENT=	Memory debugging and profiling tool
WWW=		https://www.valgrind.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		autoreconf cpe gmake pathfix perl5 pkgconfig shebangfix \
		python:run tar:bz2
USE_PERL5=	build
SHEBANG_FILES=	callgrind/callgrind_annotate.in callgrind/callgrind_control.in \
		cachegrind/cg_merge.in cachegrind/cg_diff.in \
		cachegrind/cg_annotate.in
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL}

PIE_UNSAFE=	yes
SSP_UNSAFE=	yes
LIB32_PATH?=	/usr/lib32/libc.so

CONFLICTS=	valgrind

# Valgrind needs to read debuginfo from its own preload shared libraries
# (quote from README_PACKAGERS
#-- Don't strip the debug info off lib/valgrind/$platform/vgpreload*.so
#   in the installation tree.  Either Valgrind won't work at all, or it
#   will still work if you do, but will generate less helpful error
#   messages.)
STRIP=			# empty

PORTDOCS=		html

OPTIONS_DEFINE=		DOCS MANPAGES MPI
OPTIONS_DEFINE_amd64=	32BIT
OPTIONS_DEFAULT=	MANPAGES
.if exists(${LIB32_PATH})
OPTIONS_DEFAULT_amd64=	32BIT
.endif
OPTIONS_SUB=		yes

32BIT_DESC=	Enable debugging of 32-bit programs (requires lib32)
MPI_DESC=	Enable build of MPI wrappers

DOCS_BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MANPAGES_BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

.include <bsd.port.options.mk>

PLIST_SUB+=	ARCH=${ARCH:S/i386/x86/:S/aarch64/arm64/}

.if ${ARCH} == "amd64"
PLIST_SUB+=		AMD64=""
. if !${PORT_OPTIONS:M32BIT}
CONFIGURE_ARGS+=	--enable-only64bit
PLIST_SUB+=		X86="@comment "
. else
.  if !exists(${LIB32_PATH})
IGNORE=			please either install the lib32 distribution or unset the 32BIT option
.  endif
PLIST_SUB+=		X86=""
. endif
PLIST_SUB+=		AARCH64="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=		AMD64="@comment " \
			X86="" \
			AARCH64="@comment "
.endif

.if ${ARCH} == "aarch64"
PLIST_SUB+=		AMD64="@comment " \
			X86="@comment " \
			AARCH64=""
.endif

post-patch-DOCS-off:
	@${RM} -r ${WRKSRC}/docs/html

post-build-DOCS-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html-docs

post-build-MANPAGES-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} man-pages

.include <bsd.port.mk>
