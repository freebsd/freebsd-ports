# New ports collection makefile for:	zh-ttfm
# Date created:		12 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttfm
PORTVERSION=	0.9.0
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=	keith@FreeBSD.org

USE_FREETYPE=	yes

FONTSDIR=	${PREFIX}/share/fonts/ttf/
MODULESDIR=	${PREFIX}/share/ttfm/

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/ttfm.sh ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/doc/ttfm
.for doc in README USAGE
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/ttfm
.endfor
	@${MKDIR} ${MODULESDIR}
.for module in xfreetype.ttfm xttfm.ttfm
	@${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${MODULESDIR}
.endfor
.for module in chitex.ttfm ttf2pk.ttfm xttfm-tcl.ttfm
	@${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${MODULESDIR}/${module}.nop
.endfor
	@${MKDIR} ${FONTSDIR}

.include <bsd.port.mk>
