# New ports collection makefile for:	gcl
# Date created:				Feb  8 1995
# Whom:					hsu
#
# $FreeBSD$
#

PORTNAME=	gcl
PORTVERSION=	2.6.7
PORTREVISION=	6
CATEGORIES=	lang tcl tk
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Common Lisp

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

ONLY_FOR_ARCHS=	i386

USE_TK=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	x11
CONFIGURE_ARGS=--prefix=${PREFIX} \
	--enable-ansi \
	--enable-machine=FreeBSD \
	--enable-info=${PREFIX}/info \
	--enable-tkconfig=${LOCALBASE}/lib/tk${TCL_VER} \
	--enable-tclconfig=${LOCALBASE}/lib/tcl${TCL_VER} \
	--with-x \
	--disable-dlopen \
	--disable-dynsysbfd \
	--disable-statsysbfd \
	--disable-locbfd \
	--enable-custreloc
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" C_INCLUDE_PATH=${PREFIX}/include LIBRARY_PATH=${PREFIX}/lib
MAKEFILE=	makefile

INFO=	gcl-si gcl-tk

PLIST_SUB=	GCL_VER=${PORTVERSION}

.include <bsd.port.pre.mk>

pre-configure:
	${SED} -i '' \
		-e 's|@@CFLAGS@@|${CFLAGS} -I${LOCALBASE}/include|' \
		-e 's|@@LOCALLIBS@@|-lreadline -lm -L${LOCALBASE}/lib -lgmp|' \
		${WRKSRC}/h/FreeBSD.defs

.include <bsd.port.post.mk>
