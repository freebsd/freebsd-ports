# New ports collection makefile for:	gcl
# Date created:				Feb  8 1995
# Whom:					hsu
#
# $FreeBSD$
#

PORTNAME=	gcl
PORTVERSION=	2.6.6
CATEGORIES=	lang tcl84 tk84
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcl

MAINTAINER=	markm@freebsd.org
COMMENT=	GNU Common Lisp

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4

ONLY_FOR_ARCHS=	i386 sparc64

GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	259
USE_GMAKE=	yes
USE_XLIB=	yes
CONFIGURE_ARGS=--prefix=${PREFIX} \
	--enable-machine=FreeBSD \
	--infodir=${PREFIX}/info \
	--enable-info=${PREFIX}/info \
	--enable-tkconfig=${LOCALBASE}/lib/tk8.4 \
	--enable-tclconfig=${LOCALBASE}/lib/tcl8.4 \
	--with-x \
	--x-includes=${X11BASE}/include \
	--x-libraries=${X11BASE}/lib \
	--disable-dlopen \
	--disable-dynsysbfd \
	--disable-statsysbfd \
	--disable-locbfd \
	--enable-custreloc
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" C_INCLUDE_PATH=${PREFIX}/include LIBRARY_PATH=${PREFIX}/lib
MAKEFILE=	makefile

INFO=	gcl-si gcl-tk

PLIST_SUB=	GCL_VER=${PORTVERSION}

pre-configure:
	${RM} -f ${WRKSRC}/configure
	${SED} -i '' \
		-e 's|@@CFLAGS@@|${CFLAGS} -I${LOCALBASE}/include|' \
		-e 's|@@LOCALLIBS@@|-L${LOCALBASE}/lib -lgmp -lm -lreadline|' \
		${WRKSRC}/h/FreeBSD.defs

.include <bsd.port.mk>
