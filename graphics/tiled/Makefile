# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiled
PORTVERSION=	0.12.3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics editors games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose tile map editor

USES=		desktop-file-utils shared-mime-info qmake
USE_QT4=	corelib gui opengl \
		linguisttools_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bjorn

PORTDOCS=	*

OPTIONS_DEFINE=	PYTHON DOCS
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes
PYTHON_DESC=	Enable python plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		pkgconfig python:2.7
.else
QMAKE_ARGS+=	DISABLE_PYTHON_PLUGIN=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lrelease|&-qt4|' \
		${WRKSRC}/translations/translations.pro
	@${REINPLACE_CMD} -e 's|.*\(QT += opengl\)|\1|' \
		${WRKSRC}/src/tiled/tiled.pro
	@${FIND} ${WRKSRC} -name "*.pro" -exec ${REINPLACE_CMD} -e 's|share/man|man|' {} \;

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
	${CP} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/tiled.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
