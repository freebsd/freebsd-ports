# New ports collection makefile for:   mico
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mico
PORTVERSION=	2.3.1
CATEGORIES=	devel
MASTER_SITES=	http://diamant-atm.vsb.cs.uni-frankfurt.de/~mico/

MAINTAINER=	scrappy@freebsd.org

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82

WRKSRC=		${WRKDIR}/mico

MICOVER=	`${ECHO} ${DISTNAME} | ${SED} 's/mico-//'`

.if defined(QT2)
USE_QT2=	yes
MAKE_ENV=	QT_INCLUDES="${X11BASE}/include/qt2" \
		QTVER="2"
CONFIGURE_ENV=	QTVER="2"
.else
USE_QT=		yes
MAKE_ENV=	QT_INCLUDES="${X11BASE}/include/X11/qt" \
		QTVER=""
CONFIGURE_ENV=	QTVER=""
.endif

INSTALLS_SHLIB=	yes
USE_NEWGCC=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-qt --with-gtk --with-tcl --disable-mini-stl \
		--enable-static --enable-shared

PLIST_SUB=	MICOVER="${MICOVER}"

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-install:
	${LN} -sf ${PREFIX}/lib/libmico${MICOVER}.so.1 ${PREFIX}/lib/libmico.${MICOVER}.so
	${LN} -sf ${PREFIX}/lib/libmicoaux${MICOVER}.so.1 ${PREFIX}/lib/libmicoaux.${MICOVER}.so
	${LN} -sf ${PREFIX}/lib/libmicocoss${MICOVER}.so.1 ${PREFIX}/lib/libmicocoss.${MICOVER}.so
	${LN} -sf ${PREFIX}/lib/libmicogtk${MICOVER}.so.1 ${PREFIX}/lib/libmicogtk.${MICOVER}.so
	${LN} -sf ${PREFIX}/lib/libmicoqt${MICOVER}.so.1 ${PREFIX}/lib/libmicoqt.${MICOVER}.so
	${LN} -sf ${PREFIX}/lib/libmicotcl${MICOVER}.so.1 ${PREFIX}/lib/libmicotcl.${MICOVER}.so
	${LN} -sf ${PREFIX}/lib/libmicox${MICOVER}.so.1 ${PREFIX}/lib/libmicox.${MICOVER}.so
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
