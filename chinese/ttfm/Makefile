# New ports collection makefile for:	zh-ttfm
# Date created:		12 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttfm
PORTVERSION=	0.9.4
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/ttfm/

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	A Big5/GB enhanced TrueType Font Manager

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

FONTSDIR=	${PREFIX}/share/fonts/TrueType/
MODULESDIR=	${PREFIX}/share/ttfm/

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/ttfm.sh ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/doc/ttfm
.for doc in README USAGE
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/ttfm
.endfor
	@${INSTALL_MAN} ${WRKSRC}/ttfm.sh.1 ${PREFIX}/man/man1
	@${MKDIR} ${MODULESDIR}
.for module in gscjk.ttfm xttfm.ttfm
	@${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${MODULESDIR}
.endfor
	@${MKDIR} ${FONTSDIR}

MAN1=	ttfm.sh.1

.include <bsd.port.mk>
