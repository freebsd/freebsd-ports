# Created by: Jeffery Hansen <hansen@cmu.edu>
# $FreeBSD$

PORTNAME=	tkgate
DISTVERSION=	2.0-b10
CATEGORIES=	cad
MASTER_SITES=	http://www.tkgate.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk based digital circuit editor and simulator

LICENSE=	GPLv2 # (or later)

GNU_CONFIGURE=	yes
USES=		iconv
USE_TK=		84+

MAN1=		gmac.1 tkgate.1 verga.1

TKGATE_IPATH=	-I${TK_INCLUDEDIR} -I${TCL_INCLUDEDIR}
TKGATE_LIBS=	-ltk${TK_VER:S/.//} -ltcl${TCL_VER:S/.//} -lX11 -lm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|g' ${WRKSRC}/scripts/tree.tcl
	@${REINPLACE_CMD} -e \
	    's|%%TCL_VER%%|${TCL_VER}|g; \
	     s|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|g; \
	     s|%%LOCALBASE%%|${LOCALBASE}|g' \
	     ${WRKSRC}/configure

.include <bsd.port.mk>
