# $FreeBSD$

PORTNAME=	librecad
PORTVERSION=	1.0.3
CATEGORIES=	cad
MASTER_SITES=	GITHUB

MAINTAINER=	makc@FreeBSD.org
COMMENT=	2D CAD system

BUILD_DEPENDS=	${LOCALBASE}/lib/libmuparser.a:${PORTSDIR}/math/muparser

USE_QT4=	help qt3support help-tools_build moc_build qmake_build \
		rcc_build uic_build uic3_build
USES=		qmake
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

USE_GITHUB=	yes
GH_ACCOUNT=	LibreCAD
GH_PROJECT=	LibreCAD
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	c1f2eb6

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/src/lib/engine/rs_system.cpp
	${REINPLACE_CMD} -e \
		'/^Icon/s,librecad,${PREFIX}/share/pixmaps/librecad.png,' \
		${WRKSRC}/desktop/librecad.desktop

post-build:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/lrelease-qt4 -compress librecad.pro
	${MKDIR} ${WRKSRC}/unix/resources/qm
	${INSTALL_DATA} ${WRKSRC}/ts/*.qm ${WRKSRC}/unix/resources/qm
.endif
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${SH} scripts/postprocess-unix.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/librecad ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/unix/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/desktop/librecad.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/res/main/librecad.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
