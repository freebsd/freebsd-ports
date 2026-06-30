PORTNAME=	dust3d
PORTVERSION=	1.1.6
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Low polygon 3D modeling tool
WWW=		https://dust3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		compiler:c++17-lang gmake qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	huxingyi
USE_QT=		buildtools:build \
		core gui multimedia network opengl svg widgets
WRKSRC_SUBDIR=	application

PLIST_FILES=	bin/${PORTNAME} share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTSCOUT=	skipv:unstable

post-patch:
	@${REINPLACE_CMD} -e '/PLATFORM =/s,Linux,${OPSYS},' \
		${PATCH_WRKSRC}/application.pro

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${INSTALL_WRKSRC}/../ci/appimage/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/../ci/appimage/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
