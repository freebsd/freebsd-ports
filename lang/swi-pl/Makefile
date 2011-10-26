# New ports collection makefile for: SWI-Prolog
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $FreeBSD$
#

PORTNAME=	swi-pl
PORTVERSION=	5.10.5
CATEGORIES=	lang
MASTER_SITES=	http://www.swi-prolog.org/download/stable/src/
DISTNAME=	pl-${PORTVERSION}

MAINTAINER=	g.gonter@ieee.org
COMMENT=	Edinburgh-style Prolog compiler

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		readline:${PORTSDIR}/devel/readline

LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
LIB_DEPENDS+=	Xt:${PORTSDIR}/x11-toolkits/libXt \
		jpeg:${PORTSDIR}/graphics/jpeg \
		Xpm:${PORTSDIR}/x11/libXpm
LIB_DEPENDS+=	Xft:${PORTSDIR}/x11-fonts/libXft

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SWIPLDIR=	${PORTNAME:C/-//}-${PORTVERSION}
XPCE_VER=	6.6.66

MAN1=		swipl.1 swipl-rc.1 swipl-ld.1 xpce-client.1
MANCOMPRESSED=	no

NOPRECIOUSMAKEVARS=	yes
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ARCH=${ARCH}-${OPSYS:L}
CONFIGURE_TARGET=	${ARCH}-${OPSYS:L}
CONFIGURE_ARGS=	--with-world --without-jpl

PLIST_SUB=	DISTNAME=${SWIPLDIR} ARCH=${ARCH} OS=${OPSYS:L}
PLIST_SUB+=	XPCE_VER=${XPCE_VER}

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
PLIST_SUB+=	BITS=32
.else
PLIST_SUB+=	BITS=64
.endif

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

.if (${ARCH} == "alpha")
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-configure \
		${FILESDIR}/extra-patch-src-Makefile-in
.endif

post-patch:
	@${REINPLACE_CMD} -e '/edit/s/INSTALL_PROGRAM/BSD_INSTALL_SCRIPT/g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's!^mandir=@mandir@!mandir=${MANPREFIX}/man!' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/packages/xpce/src/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e '/MALLOC_H/s/^#define \(HAVE_.*MALLOC_H\).*/\/\* #undef \1 \*\//g' \
		${WRKSRC}/src/config.h
	@${REINPLACE_CMD} -e '/EXECINFO_H/s/^#define \(HAVE_.*EXECINFO_H\).*/\/\* #undef \1 \*\//g' \
		${WRKSRC}/src/config.h

post-install:
.for f in swipl swipl-ld swipl-rc
	@${STRIP_CMD} ${PREFIX}/lib/${SWIPLDIR}/bin/${ARCH}-${OPSYS:L}/$f
.endfor
# swi-pl creates this empty directory
	${RMDIR} ${PREFIX}/lib/${SWIPLDIR}/man

.include <bsd.port.post.mk>
