# New ports collection makefile for:   mico-latest
# Version required:    2.2.1
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.11 1998/10/31 21:36:11 scrappy Exp $
#

DISTNAME=	mico-2.2.1
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk \
		qt.1:${PORTSDIR}/x11-toolkits/qt140 \
		tcl80.1:${PORTSDIR}/lang/tcl80

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mico

CONFIGURE_ARGS=	--with-qt --with-gtk --with-tcl \
		--disable-optimize --disable-shared

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
