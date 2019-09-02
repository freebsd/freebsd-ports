# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	treesheets
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	lightside@gmx.com
COMMENT=	Free form data organizer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/ZLIB_LICENSE.txt

USES=		compiler:c++17-lang desktop-file-utils gnome

USE_GITHUB=	yes
GH_ACCOUNT=	aardappel

USE_WX=		3.0+
INSTALLS_ICONS=	yes

BUILD_WRKSRC=		${WRKSRC}/src
PACKAGE_VERSION=	\"${PORTVERSION}\"
MAKE_ENV=		PACKAGE_VERSION=${PACKAGE_VERSION:Q}

PORTDATA=	images scripts translations/*/*.mo
PORTDOCS=	*.html docs
PORTEXAMPLES=	*

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/treesheets.desktop \
		share/icons/hicolor/scalable/apps/treesheets.svg \
		share/pixmaps/treesheets.png

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|sys->frame->GetPath(L"|(L"${DOCSDIR}/|' \
		${BUILD_WRKSRC}/document.h
	${REINPLACE_CMD} -e 's|wxFileName(exename).GetPath()|L"${DATADIR}"|' \
		${BUILD_WRKSRC}/myframe.h
	${REINPLACE_CMD} -e 's|frame->GetPath(L"examples|(L"${EXAMPLESDIR}|' \
		${BUILD_WRKSRC}/system.h
	${REINPLACE_CMD} -e 's|^\(Icon=\).*|\1${PORTNAME}|' \
		${WRKSRC}/TS/treesheets.desktop

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/TS && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/TS/treesheets.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/TS/images/treesheets.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/TS/images/icon32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	(cd ${WRKSRC}/TS && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	(cd ${WRKSRC}/TS/examples && ${COPYTREE_SHARE} "${PORTEXAMPLES}" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
