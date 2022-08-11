PORTNAME=	swi-pl
DISTVERSION=	8.2.3
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	swipl-${DISTVERSION}

MAINTAINER=	mailinglist@diamondbox.dk
COMMENT=	Edinburgh-style Prolog compiler

LICENSE=	BSD2CLAUSE

BROKEN_i386=	fails to link: libswipl.so: undefined reference to __atomic_compare_exchange_8
BROKEN_mips=	fails to link: libswipl.so: undefined reference to '__sync_sub_and_fetch_4'
BROKEN_mips64=	fails to link: libswipl.so: undefined reference to '__sync_sub_and_fetch_4'

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libossp-uuid.so:misc/ossp-uuid \
		libyaml.so:textproc/libyaml

USES=		cmake compiler:c11 libarchive libedit pathfix pkgconfig \
		readline shebangfix ssl xorg
USE_XORG=	ice sm x11 xext xft xinerama xpm xt

OPTIONS_DEFINE=		DOCS EXAMPLES GMP ODBC TCMALLOC THREADED XPCE
OPTIONS_DEFAULT=	GMP ODBC TCMALLOC THREADED XPCE
OPTIONS_SUB=		yes

MAKE_ENV=	XDG_DATA_DIRS=/dummy
CMAKE_ARGS=	-DSWIPL_PACKAGES_JAVA=OFF -DBUILD_TESTING=OFF

DOCS_CMAKE_ON=	-DINSTALL_DOCUMENTATION=ON
DOCS_CMAKE_OFF=	-DINSTALL_DOCUMENTATION=OFF

TCMALLOC_DESC=		Use tcmalloc instead of default freebsd jemalloc
TCMALLOC_CMAKE_ON=	-DUSE_TCMALLOC=ON
TCMALLOC_CMAKE_OFF=	-DUSE_TCMALLOC=OFF
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

XPCE_DESC=		Install XPCE graphical support
XPCE_CMAKE_ON=		-DSWIPL_PACKAGES_X=ON
XPCE_CMAKE_OFF=		-DSWIPL_PACKAGES_X=OFF
XPCE_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
XPCE_USES=		jpeg

GMP_DESC=		Enable bignum and rational numbers
GMP_CMAKE_ON=		-DUSE_GMP=ON
GMP_CMAKE_OFF=		-DUSE_GMP=OFF
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

THREADED_DESC=		Enable support for Prolog threads
THREADED_CMAKE_ON=	-DMULTI_THREADED=ON
THREADED_CMAKE_OFF=	-DMULTI_THREADED=OFF

ODBC_DESC=		Enable ODBC and CQL packages
ODBC_CMAKE_ON=		-DSWIPL_PACKAGES_ODBC=ON
ODBC_CMAKE_OFF=		-DSWIPL_PACKAGES_ODBC=OFF
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

.include <bsd.port.options.mk>

SHEBANG_FILES=	library/dialect/sicstus/swipl-lfr.pl
SHEBANG_LANG=	swipl

CMAKE_BUILD_TYPE=	Release

NOPRECIOUSMAKEVARS=	yes

.include <bsd.port.pre.mk>

USE_LDCONFIG=	${PREFIX}/lib/swipl/lib/${ARCH}-${OPSYS:tl}

PLIST_SUB+=	ARCH=${ARCH} OS=${OPSYS:tl}

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/' \
		${WRKSRC}/packages/cpp/SWI-cpp.h
	@${REINPLACE_CMD} -e 's|share/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-install-XPCE-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/swipl/lib/${ARCH}-${OPSYS:tl}/pl2xpce.so

.include <bsd.port.post.mk>
