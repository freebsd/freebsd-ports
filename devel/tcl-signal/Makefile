# Created by: gahr
# $FreeBSD$

PORTNAME=	tcl-signal
PORTVERSION=	1.4.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.nyx.net/~mschwart/
DISTNAME=	signal_ext${PORTVERSION:R:R}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Dynamically loadable signal handling for Tcl/Tk scripts

USES+=		tcl:tea
ALL_TARGET=	signal.so

CONFIGURE_ENV+=	TCL_INC_DIR=${TCL_INCLUDEDIR}

PLIST_FILES=	lib/signal/signal.so \
		lib/signal/pkgIndex.tcl

post-patch:
	${REINPLACE_CMD} -e 's|\.\./lib||' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|mkdir|${MKDIR}|; s|@TCL_PACKAGE_PATH@|@TCL_PREFIX@/lib|g' ${WRKSRC}/Makefile.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/signal
	${INSTALL_DATA} ${WRKSRC}/signal.so ${STAGEDIR}${PREFIX}/lib/signal
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/signal

.include <bsd.port.mk>
