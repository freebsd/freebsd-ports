# New ports collection makefile for:   mico
# Version required:    2.2.7
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	mico-2.3.0
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		tcl80.1:${PORTSDIR}/lang/tcl80

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_NEWGCC=	yes

.if defined(QT2)
USE_QT2=	yes
MAKE_ENV=	QT_INCLUDE="${X11BASE}/include/qt2"
.else
USE_QT=		yes
MAKE_ENV=	QT_INCLUDE="${X11BASE}/include/qt"
.endif

USE_AUTOCONF=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mico

CONFIGURE_ARGS=	--with-qt --with-gtk --with-tcl --disable-mini-stl \
		--enable-static --enable-shared
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-install:
	${LN} -s ${PREFIX}/lib/libmico2.3.0.so.1 ${PREFIX}/lib/libmico.2.3.0.so
	${LN} -s ${PREFIX}/lib/libmicoaux2.3.0.so.1 ${PREFIX}/lib/libmicoaux.2.3.0.so
	${LN} -s ${PREFIX}/lib/libmicocoss2.3.0.so.1 ${PREFIX}/lib/libmicocoss.2.3.0.so
	${LN} -s ${PREFIX}/lib/libmicogtk2.3.0.so.1 ${PREFIX}/lib/libmicogtk.2.3.0.so
	${LN} -s ${PREFIX}/lib/libmicoqt2.3.0.so.1 ${PREFIX}/lib/libmicoqt.2.3.0.so
	${LN} -s ${PREFIX}/lib/libmicotcl2.3.0.so.1 ${PREFIX}/lib/libmicotcl.2.3.0.so
	${LN} -s ${PREFIX}/lib/libmicox2.3.0.so.1 ${PREFIX}/lib/libmicox.2.3.0.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@strip ${PREFIX}/bin/containmentd
	@strip ${PREFIX}/bin/eventd
	@strip ${PREFIX}/bin/idl
	@strip ${PREFIX}/bin/imr
	@strip ${PREFIX}/bin/iordump
	@strip ${PREFIX}/bin/ird
	@strip ${PREFIX}/bin/mico-cpp
	@strip ${PREFIX}/bin/micod
	@strip ${PREFIX}/bin/noded
	@strip ${PREFIX}/bin/nsadmin
	@strip ${PREFIX}/bin/nsd
	@strip ${PREFIX}/bin/propertyd
	@strip ${PREFIX}/bin/proxyd
	@strip ${PREFIX}/bin/randomd
	@strip ${PREFIX}/bin/referenced
	@strip ${PREFIX}/bin/timed
	@strip ${PREFIX}/bin/traderd
	@strip ${PREFIX}/bin/traversald

.include <bsd.port.mk>
