# New ports collection makefile for:   mico
# Version required:    2.0.6
# Date created:        31 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.1.1.1 1998/07/04 20:41:51 steve Exp $
#

DISTNAME=	mico-2.0.6
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt
LIB_DEPENDS=	gtk\\.1\\.0:${PORTSDIR}/x11-toolkits/gtk

WRKSRC=		${WRKDIR}/mico

CONFIGURE_ARGS=	--with-qt=${X11BASE}/include/X11/qt \
		--with-gtk=${X11BASE}/include/gtk --with-tcl=/usr/include \
		--disable-optimize

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
