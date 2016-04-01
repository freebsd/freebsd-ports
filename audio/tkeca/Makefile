# $FreeBSD$

PORTNAME=	tkeca
PORTVERSION=	4.4.3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Tk interface to ecasound

LICENSE=	GPLv2

RUN_DEPENDS=	normalize:audio/normalize \
		ecasound:audio/ecasound

USES=		desktop-file-utils tk

NO_BUILD=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '3s,^exec wish,exec ${WISH},' ${WRKSRC}/tkeca.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkeca.tcl ${STAGEDIR}${PREFIX}/bin/tkeca
	${INSTALL_DATA} ${WRKSRC}/tkeca.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/tkeca.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tkeca.html ${WRKSRC}/README.tkeca \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
