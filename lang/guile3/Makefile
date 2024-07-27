PORTNAME?=	guile
DISTVERSION=	3.0.10
CATEGORIES=	lang scheme
MASTER_SITES=	GNU
PKGNAMESUFFIX?=	3

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension
WWW=		https://www.gnu.org/software/guile/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

USES=		tar:lz

# The -aclocal slave port includes this file to get the version,
# distinfo, etc., but needs none of the definitions. So almost all
# of the file is inside this .if

.if empty(NO_BUILD)

LIB_DEPENDS=	libunistring.so:devel/libunistring \
		libffi.so:devel/libffi

# the aclocal/guile.m4 from this version is shared with guile2,
# so it's hived off into a separate port to avoid a conflict.
RUN_DEPENDS=	guile-aclocal>=3:lang/guile-aclocal

USES+=		guile:${PORTVERSION:R},env \
		charsetfix compiler:c11 cpe gmake iconv libtool \
		pathfix pkgconfig readline localbase
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-suffix=-${GUILE_VER} \
		--enable-lto=no
# LTO is unconditionally off here because it fails to build with llvm,
# fails to build even with gcc on some arches (reported for armv7 in
# particular), and making it conditional on gcc/arch is trickier than
# is strictly necessary. LTO_UNSAFE stops the framework from trying to
# enable it for us if the user asks. Don't re-enable it unless you
# tested build+run on more than just amd64/arm46.
LTO_UNSAFE=	yes

# eliminate some pointless configure warnings/errors
CONFIGURE_ENV+= gl_cv_func_working_mktime=yes \
		ac_cv_header_sys_timeb_h=0

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

INFO=		guile r5rs

INFO_PATH=	${GUILE_INFO_PATH}

OPTIONS_DEFINE=	NLS THREADS MINIGMP
OPTIONS_DEFAULT=THREADS
OPTIONS_SUB=	yes

MINIGMP_DESC=	Use embedded mini-gmp rather than external libgmp

MINIGMP_LIB_DEPENDS_OFF= libgmp.so:math/gmp
MINIGMP_CONFIGURE_ENABLE= mini-gmp

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

THREADS_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
THREADS_LIB_DEPENDS_OFF=libgc.so:devel/boehm-gc
THREADS_CONFIGURE_ON=	--with-bdw-gc=bdw-gc-threaded
THREADS_CONFIGURE_OFF=	--with-bdw-gc=bdw-gc
THREADS_CONFIGURE_WITH=	threads

# Upstream bugfixes: these aren't optional because the release version
# has a broken (spawn*) function, which breaks guile-config, which
# breaks builds of some dependent ports.

# EXTRA_PATCHES=	${PATCHDIR}/extra-patch-upstream-fixes.patch

# The prebuilt bytecode files are reported not to work on powerpc.

post-patch:
	@${RM} -r ${WRKSRC}/prebuilt/32-bit-big-endian

# DO NOT try and add rules here to strip .go files, no matter how loudly
# testport / stage-qa shouts at you about it, because .go files (which are
# compiled bytecode) are not intended to be stripped and doing so causes
# breakage at run time.

post-install:
	for p in guile guild guile-tools guile-config guile-snarf; do \
	  ${LN} -s $${p}-${GUILE_VER} ${STAGEDIR}${PREFIX}/bin/$${p}${GUILE_SFX}; \
	done
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/guile-${GUILE_VER}.1 \
	      ${STAGEDIR}${PREFIX}/share/man/man1/guile${GUILE_SFX}.1

.endif # empty(NO_BUILD)

.include <bsd.port.mk>
