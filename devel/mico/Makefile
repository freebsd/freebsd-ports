# New ports collection makefile for:   mico
# Version required:    2.2.3
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.25 1998/11/16 03:25:26 scrappy Exp $
#

DISTNAME=	mico-2.2.3
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsdelf${OSREL}/2.8.1/libstdc++.a
.else
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${OSREL}/2.8.1/libstdc++.a
.endif

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk \
		tcl80.1:${PORTSDIR}/lang/tcl80
BUILD_DEPENDS=	g++28:${PORTSDIR}/lang/gcc28 \
		${LIBSTDC}:${PORTSDIR}/lang/glibstdc++28

CC=		gcc28
CXX=		g++28

USE_QT=		yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mico

CONFIGURE_ARGS=	--with-qt --with-gtk --with-tcl \
		--disable-optimize --disable-mini-stl

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m 

.include <bsd.port.post.mk>
