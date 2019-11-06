# Created by: Michael Butschky <butsch@computi.erols.com>
# $FreeBSD$

PORTNAME=	swi-pl
PORTVERSION=	7.6.4
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	swipl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Edinburgh-style Prolog compiler

LICENSE=	BSD2CLAUSE

BROKEN_mips=		fails to link: libswipl.so: undefined reference to '__sync_sub_and_fetch_4'
BROKEN_mips64=		fails to link: libswipl.so: undefined reference to '__sync_sub_and_fetch_4'

LIB_DEPENDS=	libgmp.so:math/gmp \
		libodbc.so:databases/unixODBC \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpcre.so:devel/pcre

SWIPLDIR=	${PORTNAME:C/-//}-${PORTVERSION}

NOPRECIOUSMAKEVARS=	yes

USES=		compiler:c11 libedit gmake jpeg libarchive pathfix pkgconfig \
		readline shebangfix ssl xorg
USE_XORG=	ice sm x11 xext xft xinerama xpm xt

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ARCH=${ARCH}-${OPSYS:tl}
CONFIGURE_TARGET=	${ARCH}-${OPSYS:tl}
CONFIGURE_ARGS=	--with-world --without-jpl --enable-shared
MAKE_ARGS=	DISABLE_PKGS=jpl \
		ac_cv_lib_ossp_uuid_uuid_create=no \
		ac_cv_lib_uuid_uuid_create=no

SHEBANG_LANG=	swipl
SHEBANG_FILES=	library/dialect/sicstus/swipl-lfr.pl \
		packages/http/examples/demo_inetd

PLIST_SUB=	DISTNAME=${SWIPLDIR} ARCH=${ARCH} OS=${OPSYS:tl} \
		VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH:M*64*}
PLIST_SUB+=	BITS=64
.else
PLIST_SUB+=	BITS=32
.endif

.if (${ARCH} == amd64)
ARCH=		x86_64
.endif

.if (${ARCH} == aarch64)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-skip-gnu-qsort
.endif

post-configure:
.if ${ARCH} != i386
	@${REINPLACE_CMD} -e '/^CMFLAGS=/s/$$/ -fPIC/' \
		${WRKSRC}/packages/Dialect.defs
.endif
	@{ ${ECHO} "#define HAVE_DLOPEN 1";  ${ECHO} "#define HAVE_DLADDR 1"; }\
		>> ${WRKSRC}/src/config.h

post-patch:
	@${REINPLACE_CMD} -e 's!^mandir=@mandir@!mandir=${MANPREFIX}/man!' \
		-e '/-o $$@ $$(PLOBJ)/s/$$/ $$(LIBS)/' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/packages/xpce/src/Makefile.in
	@${REINPLACE_CMD} -e '/EXAMPLEEXE/s/INSTALL_PROGRAM/INSTALL_SCRIPT/' \
		${WRKSRC}/packages/http/Makefile.in \
		${WRKSRC}/packages/pldoc/Makefile.in
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/' \
		${WRKSRC}/packages/cpp/SWI-cpp.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xpce-client \
		${STAGEDIR}${PREFIX}/lib/${SWIPLDIR}/lib/${ARCH}-${OPSYS:tl}/pl2xpce.so

.include <bsd.port.post.mk>
