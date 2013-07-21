# Created by: Michael Butschky <butsch@computi.erols.com>
# $FreeBSD$

PORTNAME=	swi-pl
PORTVERSION=	6.4.1
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	pl-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Edinburgh-style Prolog compiler

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		readline:${PORTSDIR}/devel/readline \
		jpeg:${PORTSDIR}/graphics/jpeg

OPTIONS_SINGLE=	ODBC
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC
OPTIONS_DEFAULT=UNIXODBC

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SWIPLDIR=	${PORTNAME:C/-//}-${PORTVERSION}

MAN1=		swipl.1 swipl-rc.1 swipl-ld.1 xpce-client.1
MANCOMPRESSED=	no

NOPRECIOUSMAKEVARS=	yes
USE_GMAKE=	yes
USE_XORG=	xft xpm xt
USES=		pkgconfig pathfix
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ARCH=${ARCH}-${OPSYS:L}
CONFIGURE_TARGET=	${ARCH}-${OPSYS:L}
CONFIGURE_ARGS=	--with-world --without-jpl
MAKE_ARGS=	DISABLE_PKGS="jpl"

PLIST_SUB=	DISTNAME=${SWIPLDIR} ARCH=${ARCH} OS=${OPSYS:L}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
.else
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
.endif

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

post-patch:
	@${REINPLACE_CMD} -e 's!^mandir=@mandir@!mandir=${MANPREFIX}/man!' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/packages/xpce/src/Makefile.in
	@${REINPLACE_CMD} -e '/EXAMPLEEXE/s/INSTALL_PROGRAM/INSTALL_SCRIPT/' \
		${WRKSRC}/packages/http/Makefile.in \
		${WRKSRC}/packages/pldoc/Makefile.in

.include <bsd.port.post.mk>
