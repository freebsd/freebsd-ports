# New ports collection makefile for:	gcl
# Date created:				Feb  8 1995
# Whom:					hsu
#
# $FreeBSD$
#

PORTNAME=	gcl
PORTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	lang tcl84 tk84
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcl

MAINTAINER=	markm@freebsd.org
COMMENT=	GNU Common Lisp

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

ONLY_FOR_ARCHS=	i386 sparc64

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
CONFIGURE_ARGS=--prefix=${PREFIX} \
	--enable-machine=FreeBSD \
	--enable-ansi \
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
MAKEFILE=	makefile

INFO=	gcl gcl-si gcl-tk

PLIST_SUB=	GCL_VER=${PORTVERSION}

pre-configure:
	${RM} -f ${WRKSRC}/configure
	${SED} -i '.PRE-SED' -e 's|@@CFLAGS@@|${CFLAGS}|' ${WRKSRC}/h/FreeBSD.defs

.include <bsd.port.mk>
