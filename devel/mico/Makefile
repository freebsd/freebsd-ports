# New ports collection makefile for:   mico-latest
# Version required:    2.1.0
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.6 1998/08/23 04:36:04 scrappy Exp $
#

DISTNAME=	mico-2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk
BUILD_DEPENDS=	g++28:${PORTSDIR}/lang/gcc28 \
		${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${OSREL}/2.8.1/libstdc++.a:${PORTSDIR}/lang/glibstdc++28

BROKEN=		build

CXX=		g++28
CC=		gcc28

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mico

CONFIGURE_ARGS=	--with-qt --with-gtk --with-tcl=/usr/include \
		--disable-optimize --disable-mini-stl --disable-shared

MAN1=		idl.1 imr.1 nsadmn.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

pre-patch:
	cd ${WRKSRC}/idl; flex -B -+ -8 -oscanner.cc scanner.l

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
