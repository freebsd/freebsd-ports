# Created by: Michael Butschky <butsch@computi.erols.com>
# $FreeBSD$

PORTNAME=	swi-pl
DISTVERSION=	8.2.3
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	swipl-${DISTVERSION}

MAINTAINER=	mailinglist@diamondbox.dk
COMMENT=	Edinburgh-style Prolog compiler

LICENSE=	BSD2CLAUSE

BROKEN_i386=	fails to link: libswipl.so: undefined reference to __atomic_compare_exchange_8
BROKEN_mips=	fails to link: libswipl.so: undefined reference to '__sync_sub_and_fetch_4'
BROKEN_mips64=	fails to link: libswipl.so: undefined reference to '__sync_sub_and_fetch_4'

LIB_DEPENDS=	libgmp.so:math/gmp \
		libodbc.so:databases/unixODBC \
		libpcre.so:devel/pcre \
		libossp-uuid.so:misc/ossp-uuid \
		libyaml.so:textproc/libyaml

USES=		compiler:c11 libedit cmake libarchive pathfix pkgconfig \
		readline shebangfix ssl
USE_XORG=	ice sm x11 xext xft xinerama xpm xt

OPTIONS_DEFINE=		TCMALLOC EXAMPLES XPCE
OPTIONS_DEFAULT=	XPCE TCMALLOC
OPTIONS_SUB=    	yes

CMAKE_ARGS=	-DSWIPL_PACKAGES_JAVA=OFF -DBUILD_TESTING=OFF -DINSTALL_DOCUMENTATION=OFF

TCMALLOC_DESC=		Use tcmalloc instead of default malloc
TCMALLOC_CMAKE_ON=	-DUSE_TCMALLOC=ON
TCMALLOC_CMAKE_OFF=	-DUSE_TCMALLOC=OFF
TCMALLOC_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

XPCE_DESC=		Install XPCE graphical support
XPCE_CMAKE_ON=		-DSWIPL_PACKAGES_X=ON
XPCE_CMAKE_OFF=		-DSWIPL_PACKAGES_X=OFF
XPCE_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libjpeg.so:graphics/jpeg-turbo
XCPE_USES=		jpeg xorg

.include <bsd.port.options.mk>

SHEBANG_FILES=	library/dialect/sicstus/swipl-lfr.pl
SHEBANG_LANG=	swipl

CMAKE_BUILD_TYPE=	Release

NOPRECIOUSMAKEVARS=	yes

.include <bsd.port.pre.mk>

USE_LDCONFIG=	${PREFIX}/lib/swipl/lib/${ARCH}-${OPSYS:tl}

PLIST_SUB+=	ARCH=${ARCH} OS=${OPSYS:tl}

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
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
