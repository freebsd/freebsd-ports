# Created by: Michael Butschky <butsch@computi.erols.com>
# $FreeBSD$

PORTNAME=	swi-pl
PORTVERSION=	6.6.2
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	pl-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Edinburgh-style Prolog compiler

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

# note that the ports unixodbc and libiodbc conflict
OPTIONS_SINGLE=	ODBC
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC
OPTIONS_DEFAULT=UNIXODBC
UNIXODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
IODBC_LIB_DEPENDS=	libiodbc.so:${PORTSDIR}/databases/libiodbc

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SWIPLDIR=	${PORTNAME:C/-//}-${PORTVERSION}

NOPRECIOUSMAKEVARS=	yes
USE_XORG=	xft xpm xt
USES=		pkgconfig pathfix gmake shebangfix
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ARCH=${ARCH}-${OPSYS:L}
CONFIGURE_TARGET=	${ARCH}-${OPSYS:L}
CONFIGURE_ARGS=	--with-world --without-jpl --enable-shared
MAKE_ARGS=	DISABLE_PKGS=jpl \
		ac_cv_lib_ossp_uuid_uuid_create=no ac_cv_lib_uuid_uuid_create=no

SHEBANG_LANG=	swipl
swipl_OLD_CMD=	/usr/bin/swipl
swipl_CMD=	${LOCALBASE}/bin/swipl
SHEBANG_FILES=	library/dialect/sicstus/swipl-lfr.pl \
		packages/http/examples/demo_inetd

PLIST_SUB=	DISTNAME=${SWIPLDIR} ARCH=${ARCH} OS=${OPSYS:L} \
		VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386" || ${ARCH} == "powerpc")
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
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/packages/xpce/src/Makefile.in
	@${REINPLACE_CMD} -e '/EXAMPLEEXE/s/INSTALL_PROGRAM/INSTALL_SCRIPT/' \
		${WRKSRC}/packages/http/Makefile.in \
		${WRKSRC}/packages/pldoc/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xpce-client \
		${STAGEDIR}${PREFIX}/lib/${SWIPLDIR}/lib/${ARCH}-freebsd/pl2xpce.so

.include <bsd.port.post.mk>
