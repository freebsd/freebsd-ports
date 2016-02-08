# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	cavezofphear
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	http://www.x86.no/cavezofphear/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	phear-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Boulder Dash / Digger-like game written using ncurses

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

USES=		gmake ncurses tar:bzip2
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	phear

PORTDOCS=	ChangeLog README README-EDITOR TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|\./data|${DATADIR}/data|' ${WRKSRC}/src/chk.c
	@${REINPLACE_CMD} -e 's|\./phear|phear|' ${WRKSRC}/README-EDITOR

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/phear ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}; ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
