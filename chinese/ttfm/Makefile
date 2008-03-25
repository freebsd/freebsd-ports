# New ports collection makefile for:	zh-ttfm
# Date created:		12 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttfm
PORTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	chinese print
MASTER_SITES=	LOCAL/rafan/chinese

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A Big5/GB enhanced TrueType Font Manager

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

PORTDOCS=	README USAGE
MAN1=		ttfm.sh.1

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/modules/gscjk.ttfm \
		${WRKSRC}/modules/xttfm.ttfm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/ttfm.sh ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/ttfm.sh.1 ${MANPREFIX}/man/man1/
	@${MKDIR} ${DATADIR}
.for module in gscjk.ttfm xttfm.ttfm
	${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${DATADIR}/
.endfor

.include <bsd.port.mk>
