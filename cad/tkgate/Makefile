# New ports collection makefile for:	tkgate
# Date created:				28 May 1999
# Whom:					Jeffery Hansen <hansen@cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	tkgate
PORTVERSION=	1.8.7
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	ftp://gadoid.ices.cmu.edu/pub/tkgate/ \
		http://www.cs.earlham.edu/~charliep/courses/cs320/TkGate/ \
		http://ark2.media.eng.hokudai.ac.jp/microprocessor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tcl/Tk based digital circuit editor and simulator

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	x11
USE_TCL_BUILD=	yes
USE_TK_BUILD=	yes
USE_TCL=	yes
USE_TK=		yes
USE_IMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		gmac.1 tkgate.1

TKGATE_IPATH=	-I${TK_INCLUDEDIR} -I${TCL_INCLUDEDIR}
TKGATE_LIBS=	-ltk${TK_VER:S/.//} -ltcl${TCL_VER:S/.//} -lX11 -lm

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g ; \
		 s|dl socket nsl||g ; \
		 /^#define TKGATE_IPATH/s|-I.*|${TKGATE_IPATH}|g ; \
		 /^#define TKGATE_LIBS/s|-l.*|${TKGATE_LIBS}|g ; \
		 /^#define TKGATE_GCCFLAGS/s|-O||g ; \
		 /^#define TKGATE_CC/s|gcc|${CC}|g' ${WRKSRC}/config.h
.for file in tree.tcl elistbox.tcl
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${WISH}|g' ${WRKSRC}/scripts/${file}
.endfor

.include <bsd.port.mk>
