PORTNAME=	crashtest
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	games education
MASTER_SITES=	http://www.stolk.org/crashtest/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Educational crash simulator

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibul.a:x11-toolkits/plib
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libode.so:devel/ode

USES=		gl pkgconfig
USE_GL=		gl glu

BUILD_WRKSRC=	${WRKSRC}/src-crashtest

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES="${PORTNAME}" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;Simulation;Physics;" \
		""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/src-crashtest/crashtest.cxx

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/models
	${INSTALL_DATA} ${WRKSRC}/models-crashtest/*.3ds ${STAGEDIR}${DATADIR}/models
	${INSTALL_DATA} ${WRKSRC}/models-crashtest/*.ac ${STAGEDIR}${DATADIR}/models
	${INSTALL_DATA} ${WRKSRC}/models-crashtest/*.bmp ${STAGEDIR}${DATADIR}/models

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
