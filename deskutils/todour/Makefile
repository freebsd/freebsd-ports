PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	2.20
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	Qt-based UI for editing of todo.txt files

LICENSE=	GPLv2

USES=		qmake qt:5
USE_QT=		buildtools_build core gui network widgets
USE_GITHUB=	yes
GH_ACCOUNT=	SverrirValgeirsson
GH_PROJECT=	Todour
GH_TUPLE=	gamecreature:QtAwesome:86f3bb8:gamecreature/QtAwesome \
		falceeffect:UGlobalHotkey:2edc485:falceeffect/UGlobalHotkey

DESKTOP_ENTRIES="${GH_PROJECT}" "${COMMENT}" "${PORTNAME}" "${PORTNAME}" \
		"Utility;TextTools;" false

PLIST_FILES=	bin/${PORTNAME} \
		share/icons/hicolor/512x512/apps/${PORTNAME}.png

post-patch:
	@${REINPLACE_CMD} -e 's,$$$$system(perl ver.*,${PORTVERSION},' \
		${WRKSRC}/Todour.pro

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/Todour \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${INSTALL_WRKSRC}/newicon.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/${PORTNAME}.png

.include <bsd.port.mk>
