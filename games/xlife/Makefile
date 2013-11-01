# Created by: asami
# $FreeBSD$

PORTNAME=	xlife
PORTVERSION=	6.7.5
CATEGORIES=	games
MASTER_SITES=	http://litwr2.atspace.eu/xlife/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	John Horton Conway's Game of Life

LICENSE=	MIT GPLv2
LICENSE_COMB=	multi

RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_BZIP2=	yes
USES=		imake:notall
USE_XORG=	x11

PORTDOCS=	*

DESKTOP_ENTRIES="XLife" "" "" "${PORTNAME}" "" false

DOC_FILES=	CHANGES HACKING HOW-TO-INSTALL INSTALL MISSED README \
		SHORT-INFO XLIFE-HISTORY.dot changelog.debian changelog.openbsd

.include <bsd.port.options.mk>

post-extract:
	@${LN} -sf xlife.man ${WRKSRC}/xlife.6

pre-patch:
.for i in xlife6.7to6.7.1.patch xlife6.7.1to6.7.2.patch xlife6.7.2to6.7.3.patch
	@(${CAT} ${WRKDIR}/${i} | ${PATCH} -d ${WRKSRC} -p1 -s)
.endfor

post-patch:
	@${REINPLACE_CMD} -e \
		'/CDEBUGFLAGS[[:space:]]/s|^|XCOMM | ; \
		 s|/usr/share/xlife|${DATADIR}|' ${WRKSRC}/Imakefile
	@${REINPLACE_CMD} -e \
		's|GAWKPATH|${LOCALBASE}/bin/gawk|' ${WRKSRC}/table2r

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} gen-multirules xlife \
		${STAGEDIR}${PREFIX}/bin)
	@${LN} -sf xlife ${STAGEDIR}${PREFIX}/bin/lifeconv
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} table2r \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} xlife.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6)
	@${LN} -sf xlife.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/lifeconv.6
	@${MKDIR} ${STAGEDIR}${DATADIR}/patterns
	(cd ${WRKSRC}/patterns && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/patterns)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}/doc)

.include <bsd.port.mk>
