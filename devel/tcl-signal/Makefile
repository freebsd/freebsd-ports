# New ports collection Makefile for:	tcl-signal
# Date created:				16 August 2012
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	tcl-signal
PORTVERSION=	1.4.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.nyx.net/~mschwart/
DISTNAME=	signal_ext${PORTVERSION:R:R}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Dynamically loadable signal handling for Tcl/Tk scripts

USE_TCL=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	signal.so
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR}
CONFIGURE_ENV+=	TCL_INC_DIR=${TCL_INCLUDEDIR}

PLIST_FILES=	lib/signal/signal.so \
		lib/signal/pkgIndex.tcl

post-patch:
	${REINPLACE_CMD} -e 's|\.\./lib||' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|mkdir|${MKDIR}|; s|@TCL_PACKAGE_PATH@|@TCL_PREFIX@/lib|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
