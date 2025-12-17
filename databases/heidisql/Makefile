PORTNAME=	heidisql
DISTVERSION=	12.14.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	a lightweight client for managing multiple databases
WWW=		https://www.heidisql.com/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		desktop-file-utils fpc lazarus:flavors xorg
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	HeidiSQL
GH_PROJECT=	HeidiSQL
GH_TAGNAME=	2967ad28b4e3172e302cb8d487c0d3a5c752b3f

LAZARUS_PROJECT_FILES+=	heidisql.lpi

LAZBUILD_ARGS=		-d

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -e 's|FPC_FULLVERSION<30204|FPC_FULLVERSION<30203|g' \
		${WRKSRC}/source/main.pas ${WRKSRC}/source/usermanager.pas
	${REINPLACE_CMD} -e 's|System.UITypes,||g' ${WRKSRC}/source/table_editor.pas \
		${WRKSRC}/source/grideditlinks.pas
	${REINPLACE_CMD} -e 's| \+ \[ofAllowMultiSelect\]||g' ${WRKSRC}/source/main.pas
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/source/apphelpers.pas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/package-skeleton/usr/share/applications/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/res/deb-package-icon.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/extra/ini/*.ini ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
