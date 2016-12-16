# Created by: asami
# $FreeBSD$

PORTNAME=	xlife
PORTVERSION=	6.7.6
CATEGORIES=	games
MASTER_SITES=	http://litwr2.atspace.eu/xlife/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	John Horton Conway's Game of Life

LICENSE=	MIT GPLv2
LICENSE_COMB=	multi

RUN_DEPENDS=	gawk:lang/gawk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USES=		imake:notall tar:bzip2
USE_XORG=	x11

PORTDOCS=	*

DESKTOP_ENTRIES="XLife" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;Simulation;" \
		""

OPTIONS_DEFINE=	DOCS

post-extract:
	@${LN} -sf xlife.man ${WRKSRC}/xlife.6

pre-patch:
.for i in 6.7to6.7.1 6.7.1to6.7.2 6.7.2to6.7.3 6.7.3to6.7.4 6.7.4to6.7.5 \
	6.7.5to6.7.6
	@(${CAT} ${WRKDIR}/${PORTNAME}${i}.patch | ${PATCH} -d ${WRKSRC} -p1 -s)
.endfor

post-patch:
	@${REINPLACE_CMD} -e \
		'/CDEBUGFLAGS[[:space:]]/s|^|XCOMM | ; \
		 s|/usr/share/xlife|${DATADIR}|' ${WRKSRC}/Imakefile
	@${REINPLACE_CMD} -e \
		's|GAWKPATH|${LOCALBASE}/bin/gawk|' ${WRKSRC}/table2r

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gen-multirules ${WRKSRC}/xlife ${STAGEDIR}${PREFIX}/bin
	${LN} -sf xlife ${STAGEDIR}${PREFIX}/bin/lifeconv
	${INSTALL_SCRIPT} ${WRKSRC}/table2r ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xlife.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	${LN} -sf xlife.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/lifeconv.6
	@${MKDIR} ${STAGEDIR}${DATADIR}/patterns
	@(cd ${WRKSRC}/patterns && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/patterns)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in CHANGES HACKING MISSED README SHORT-INFO XLIFE-HISTORY.dot
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/doc)

.include <bsd.port.mk>
