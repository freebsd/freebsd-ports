# New ports collection makefile for:   mico
# Version required:    2.2.3
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $Id: Makefile,v 1.22 1998/11/14 17:50:16 jseger Exp $
#

DISTNAME=	mico-2.2.3
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

BROKEN_ELF=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsdelf${OSREL}/2.8.1/libstdc++.a
.else
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${OSREL}/2.8.1/libstdc++.a
.endif

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk \
		tcl80.1:${PORTSDIR}/lang/tcl80
BUILD_DEPENDS=	g++28:${PORTSDIR}/lang/gcc28 \
		${LIBSTDC}:${PORTSDIR}/lang/glibstdc++28 \
		autoconf:${PORTSDIR}/devel/autoconf

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

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
