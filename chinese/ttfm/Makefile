# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttfm
PORTVERSION=	0.9.5
PORTREVISION=	4
CATEGORIES=	chinese print
MASTER_SITES=	LOCAL/rafan/chinese

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A Big5/GB enhanced TrueType Font Manager

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

MAKE_ARGS=	FREETYPE_BASE=${LOCALBASE:Q} CC="${CC}"

PORTDOCS=	README USAGE
MAN1=		ttfm.sh.1

NO_STAGE=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/modules/gscjk.ttfm \
		${WRKSRC}/modules/xttfm.ttfm \
		${WRKSRC}/ttfm.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/ttfm.sh ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
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
