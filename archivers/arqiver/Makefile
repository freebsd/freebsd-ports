PORTNAME=	arqiver
DISTVERSION=	0.12.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/tsujan/${PORTNAME}/releases/download/V${DISTVERSION}/
DISTNAME=	Arqiver-${PORTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Simple Qt archive manager
WWW=		https://github.com/tsujan/Arqiver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		desktop-file-utils gl qmake tar:xz

.if ${FLAVOR} == qt5
USES+=			qt:5
USE_GL=			gl
USE_QT=			core dbus gui linguist svg widgets buildtools:build
CONFLICTS_INSTALL=	${PORTNAME}-qt6
.else
PKGNAMESUFFIX=		-qt6
USES+=			qt:6
USE_GL=			opengl
USE_QT=			base svg tools:build
CONFLICTS_INSTALL=	${PORTNAME}
.endif

OPTIONS_DEFINE=		7ZIP ARJ LZO RAR ZIP
OPTIONS_DEFAULT=	7ZIP ARJ LZO RAR ZIP

7ZIP_DESC=		7zip archive support
ARJ_DESC=		ARJ archive support
RAR_DESC=		RAR archive support
ZIP_DESC=		ZIP archive support

7ZIP_RUN_DEPENDS=	7z:archivers/7-zip
ARJ_RUN_DEPENDS=	arj:archivers/arj
LZO_RUN_DEPENDS=	lzop:archivers/lzop
RAR_RUN_DEPENDS=	rar:archivers/rar \
			unrar:archivers/unrar
ZIP_RUN_DEPENDS=	zip:archivers/zip

.include <bsd.port.mk>
