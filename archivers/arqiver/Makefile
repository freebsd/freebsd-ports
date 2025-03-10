PORTNAME=	arqiver
DISTVERSION=	1.0.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/tsujan/${PORTNAME}/releases/download/V${DISTVERSION}/
DISTNAME=	Arqiver-${PORTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Simple Qt archive manager
WWW=		https://github.com/tsujan/Arqiver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gl qmake qt:6 tar:xz
USE_GL=		opengl
USE_QT=		base svg tools:build

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
