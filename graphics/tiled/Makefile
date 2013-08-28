# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiled
PORTVERSION=	0.9.1
CATEGORIES=	graphics editors games
MASTER_SITES=	SF/tiled/tiled-qt/${PORTVERSION}
DISTNAME=	tiled-qt-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose tile map editor

USE_QT4=	corelib gui opengl \
		linguist_build qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

MAN1=		automappingconverter.1 tiled.1 tmxrasterizer.1 tmxviewer.1

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|lrelease|&-qt4|' \
		${WRKSRC}/translations/translations.pro
	@${REINPLACE_CMD} -e 's|.*\(QT += opengl\)|\1|' \
		${WRKSRC}/src/tiled/tiled.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/docs/tiled.desktop
	@${FIND} ${WRKSRC} -name "*.pro" -exec ${REINPLACE_CMD} -e 's|share/man|man|' {} \;

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX="${PREFIX}" tiled.pro

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}/
.endif

.include <bsd.port.mk>
