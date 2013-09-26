# Created by: wghicks@bellsouth.net
# $FreeBSD$

PORTNAME=	tkcon
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tk console for Tcl

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USES+=		tk

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%DOCSDIR%%|${DOCSDIR}|g; s|%%WISH%%|${WISH}|g' ${WRKSRC}/${PORTNAME}.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.tcl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/README.${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
