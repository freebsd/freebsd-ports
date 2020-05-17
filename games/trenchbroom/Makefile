# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trenchbroom
PORTVERSION=	2.0.0.b
PORTREVISION=	9
CATEGORIES=	games cad

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform level editor for Quake-engine based games

LICENSE=	GPLv3

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage

USE_GITHUB=	yes
GH_ACCOUNT=	kduske
GH_PROJECT=	TrenchBroom
GH_TAGNAME=	ed46601

USES=		cmake:insource compiler:c++11-lib gl gnome pkgconfig
USE_GL=		gl glew glu
USE_WX=		3.0+
CMAKE_ARGS=	-DAPP_BUILD_CHANNEL:STRING="Beta for ${OPSYS}/${ARCH}"
INSTALLS_ICONS=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -Rl --null std::tr1:: ${WRKSRC}/common/src | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,std::tr1::,std::,g'
	@${REINPLACE_CMD} -e 's,Build ,&Type: ,' \
		${WRKSRC}/common/src/View/AppInfoPanel.cpp
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		${WRKSRC}/common/src/IO/SystemPaths.cpp
	@${REINPLACE_CMD} -e '/return m_.*Margin/s,(),,' \
		${WRKSRC}/common/src/View/CellLayout.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/TrenchBroom ${STAGEDIR}${PREFIX}/bin
	@${RMDIR} ${WRKSRC}/Resources/help || :
	cd ${WRKSRC}/Resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.for n in 16 22 24 32 36 48 64 72 96 128 192 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${WRKSRC}/app/resources/linux/icons/icon_${n}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps/${PORTNAME}.png
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
