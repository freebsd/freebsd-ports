PORTNAME=	swi-pl
DISTVERSION=	10.0.2
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	swipl-${DISTVERSION}

MAINTAINER=	mailinglist@diamondbox.dk
COMMENT=	Edinburgh-style Prolog compiler
WWW=		https://www.swi-prolog.org/

LICENSE=	BSD2CLAUSE

BROKEN_i386=	FAILED: man/lib/clpfdlib.tex

BUILD_DEPENDS=  uuid-config:misc/ossp-uuid
LIB_DEPENDS=	libpcre2-posix.so:devel/pcre2 \
		libossp-uuid.so:misc/ossp-uuid \
		libyaml.so:textproc/libyaml \
		${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_armv7=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64le=	libunwind.so:devel/libunwind

USES=		cmake compiler:c11 libarchive libedit pathfix pkgconfig python ssl localbase:ldflags
USE_LDCONFIG=	${PREFIX}/lib/swipl/lib/${ARCH}-${OPSYS:tl}

CMAKE_ARGS=	-DSWIPL_PACKAGES_JAVA=OFF -DBUILD_TESTING=OFF -DSYSTEM_LIBEDIT=ON
.ifndef WITH_DEBUG
CMAKE_BUILD_TYPE=PGO
.endif

LDFLAGS+=	-lstdthreads
NOPRECIOUSMAKEVARS=	yes
PLIST_SUB+=	ARCH=${ARCH} OS=${OPSYS:tl}

OPTIONS_DEFINE=		DOCS EXAMPLES GMP ODBC TCMALLOC THREADED XPCE
OPTIONS_DEFAULT=	GMP ODBC TCMALLOC THREADED XPCE
OPTIONS_SUB=		yes
# devel/google-perftools broken on these
OPTIONS_EXCLUDE_aarch64= TCMALLOC
OPTIONS_EXCLUDE_armv7= TCMALLOC
OPTIONS_EXCLUDE_riscv64= TCMALLOC

DOCS_CMAKE_BOOL=	INSTALL_DOCUMENTATION

TCMALLOC_DESC=		Use tcmalloc instead of default freebsd jemalloc
TCMALLOC_CMAKE_BOOL=	USE_TCMALLOC
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

XPCE_DESC=		Install XPCE graphical support
XPCE_CMAKE_BOOL=	SWIPL_PACKAGES_GUI
XPCE_USES=		sdl
XPCE_USE=		sdl=sdl3,image3
XPCE_LIB_DEPENDS=	libcairo.so:graphics/cairo \
			libpangocairo-1.0.so:x11-toolkits/pango

GMP_DESC=		Enable bignum and rational numbers
GMP_CMAKE_BOOL=		USE_GMP
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

THREADED_DESC=		Enable support for Prolog threads
THREADED_CMAKE_BOOL=	MULTI_THREADED

ODBC_DESC=		Enable ODBC and CQL packages
ODBC_CMAKE_BOOL=	SWIPL_PACKAGES_ODBC
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

.include <bsd.port.mk>
