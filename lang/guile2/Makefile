PORTNAME=	guile
DISTVERSION=	2.2.7
PORTREVISION=	6
CATEGORIES=	lang scheme
MASTER_SITES=	GNU
PKGNAMESUFFIX=	2

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension
WWW=		https://www.gnu.org/software/guile/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libltdl.so:devel/libltdl \
		libunistring.so:devel/libunistring \
		libffi.so:devel/libffi
RUN_DEPENDS=	guile-aclocal>=3:lang/guile-aclocal

USES=		guile:${PORTVERSION:R},env \
		charsetfix compiler:c11 cpe gmake iconv libtool localbase \
		ncurses pathfix pkgconfig readline tar:lz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-suffix=-${GUILE_VER}
# eliminate some pointless configure warnings/errors
CONFIGURE_ENV+=	gl_cv_func_working_mktime=yes \
		ac_cv_header_sys_timeb_h=0

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

INFO=		guile r5rs
INFO_PATH=	${GUILE_INFO_PATH}

OPTIONS_DEFINE=	NLS THREADS
OPTIONS_DEFAULT=THREADS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

THREADS_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
THREADS_LIB_DEPENDS_OFF=libgc.so:devel/boehm-gc
THREADS_CONFIGURE_ON=	--with-bdw-gc=bdw-gc-threaded
THREADS_CONFIGURE_OFF=	--with-bdw-gc=bdw-gc
THREADS_CONFIGURE_WITH=	threads

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

.include <bsd.port.mk>
