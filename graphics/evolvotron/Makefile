PORTNAME=	evolvotron
DISTVERSION=	0.8.3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Generative software that evolves images/textures/patterns
WWW=		https://github.com/WickedSmoke/evolvotron

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		compiler:c++17-lang gl gnome python qmake qt:6
USE_CXXSTD=	c++17
USE_GL=		opengl
USE_QT=		base tools

QMAKE_ARGS=		VERSION_NUMBER="${DISTVERSION}"
QMAKE_SOURCE_PATH=	${WRKSRC}/main.pro

ICON_SIZES=	48x48 128x128

PORTDOCS=	NEWS README.md TODO USAGE evolvotron.html
OPTIONS_DEFINE=	DOCS

do-install:
.for i in evolvotron evolvotron_mutate evolvotron_render
	${INSTALL_PROGRAM} ${WRKSRC}/obj/${i}/${i} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/${i}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
.endfor
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKSRC}/dist/icon-${s:C/x.*//}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
