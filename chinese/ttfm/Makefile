# New ports collection makefile for:	zh-ttfm
# Date created:		12 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttfm
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/ttfm/

MAINTAINER=	keith@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${XFREE86_VERSION} == 4
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

USE_FREETYPE=	yes

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
.for module in abiword.ttfm gscjk.ttfm xfreetype.ttfm xttfm.ttfm
	@${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${MODULESDIR}
.endfor
.for module in chitex.ttfm ghostscript6.ttfm ttf2pk.ttfm xttfm-tcl.ttfm
	@${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${MODULESDIR}/${module}.nop
.endfor
	@${MKDIR} ${FONTSDIR}

MAN1=	ttfm.sh.1

.include <bsd.port.post.mk>
