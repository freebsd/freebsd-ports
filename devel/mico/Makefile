# New ports collection makefile for:   mico
# Version required:    2.2.3
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.16 1998/11/11 19:59:34 scrappy Exp $
#

DISTNAME=	mico-2.2.3
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk \
		tcl80.1:${PORTSDIR}/lang/tcl80 \
BUILD_DEPENDS=	g++28:${PORTSDIR}/lang/gcc28

CC=		gcc28
CXX=		g++28

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mico

CONFIGURE_ARGS=	--with-qt --with-gtk --with-tcl \
		--disable-optimize --disable-shared --disable-mini-stl

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
