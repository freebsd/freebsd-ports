# New ports collection makefile for:   mico-latest
# Version required:    2.1.0
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.3 1998/07/12 19:28:33 scrappy Exp $
#

DISTNAME=	mico-2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	gtk\\.1\\.4:${PORTSDIR}/x11/gtk \
		qt\\.1\\.33:${PORTSDIR}/x11/qt133

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt \
		g++28:${PORTSDIR}/lang/gcc28 \
		${PREFIX}/${GCC28DIR}/libstdc++.a:${PORTSDIR}/lang/glibstdc++28

CXX=		g++28
CC=		gcc28

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

GNUOSREL!=      uname -r | ${SED} -e 's/[-(].*//'
GCC28DIR=       lib/gcc-lib/i386-unknown-freebsd${GNUOSREL}/2.8.1
