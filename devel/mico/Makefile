# New ports collection makefile for:   mico
# Version required:    2.2.7
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	mico-2.2.7
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		tcl80.1:${PORTSDIR}/lang/tcl80

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_NEWGCC=	yes
USE_QT=		yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mico

CONFIGURE_ARGS=	--with-qt --with-gtk --with-tcl --disable-mini-stl
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
