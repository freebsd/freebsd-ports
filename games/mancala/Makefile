PORTNAME=	mancala
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	https://shh.thathost.com/pub-unix/files/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Implementation of the simple board game called Mancala

LICENSE=	ART10

USES=	gmake

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11

PORTDOCS=	*
PLIST_FILES=	bin/mancala
X11_LIB_DEPENDS=	libforms.so:x11-toolkits/xforms
X11_PLIST_FILES=	bin/xmancala
X11_ALL_TARGET=	xmancala
ALL_TARGET=	mancala

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^XINCDIR.*|XINCDIR = -I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^XLIBDIR.*|XLIBDIR = -L${LOCALBASE}/lib|' \
		${WRKSRC}/Makefile

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ChangeLog INSTALL NEWS README RULES
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-X11-on:
	${INSTALL_SCRIPT} ${WRKSRC}/x${PORTNAME} ${STAGEDIR}${PREFIX}/bin/x${PORTNAME}

.include <bsd.port.mk>
