# Created by: Michael Butschky <butsch@computi.erols.com>
# $FreeBSD$

PORTNAME=	swi-pl
PORTVERSION=	7.2.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	swipl-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Edinburgh-style Prolog compiler

LIB_DEPENDS=	libgmp.so:math/gmp \
		libodbc.so:databases/unixODBC

SWIPLDIR=	${PORTNAME:C/-//}-${PORTVERSION}

NOPRECIOUSMAKEVARS=	yes
USE_XORG=	xft xpm xt
USES=		gmake jpeg libarchive pathfix pkgconfig shebangfix
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ARCH=${ARCH}-${OPSYS:tl}
CONFIGURE_TARGET=	${ARCH}-${OPSYS:tl}
CONFIGURE_ARGS=	--with-world --without-jpl --enable-shared
MAKE_ARGS=	DISABLE_PKGS=jpl \
		ac_cv_lib_ossp_uuid_uuid_create=no ac_cv_lib_uuid_uuid_create=no

SHEBANG_LANG=	swipl
swipl_OLD_CMD=	/usr/bin/swipl
swipl_CMD=	${LOCALBASE}/bin/swipl
SHEBANG_FILES=	library/dialect/sicstus/swipl-lfr.pl \
		packages/http/examples/demo_inetd

PLIST_SUB=	DISTNAME=${SWIPLDIR} ARCH=${ARCH} OS=${OPSYS:tl} \
		VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386" || ${ARCH} == "powerpc" || ${ARCH} == "armv6")
PLIST_SUB+=	BITS=32
.else
PLIST_SUB+=	BITS=64
.endif

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

post-configure:
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} -e '/^CMFLAGS=/s/$$/ -fPIC/' \
		${WRKSRC}/packages/Dialect.defs
.endif
	@{ ${ECHO} "#define HAVE_DLOPEN 1";  ${ECHO} "#define HAVE_DLADDR 1"; }\
		>> ${WRKSRC}/src/config.h

post-patch:
	@${REINPLACE_CMD} -e 's!^mandir=@mandir@!mandir=${MANPREFIX}/man!' \
		-e '/-o $$@ $$(PLOBJ)/s/$$/ $$(LIBS)/' \
		-e '/ $$(SHAREDV) $$(SONAME)/d' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/packages/xpce/src/Makefile.in
	@${REINPLACE_CMD} -e '/EXAMPLEEXE/s/INSTALL_PROGRAM/INSTALL_SCRIPT/' \
		${WRKSRC}/packages/http/Makefile.in \
		${WRKSRC}/packages/pldoc/Makefile.in
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/' \
		${WRKSRC}/packages/cpp/SWI-cpp.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xpce-client \
		${STAGEDIR}${PREFIX}/lib/${SWIPLDIR}/lib/${ARCH}-freebsd/pl2xpce.so

.include <bsd.port.post.mk>
