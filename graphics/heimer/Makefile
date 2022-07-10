PORTNAME=	heimer
DISTVERSION=	3.4.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/juzzlin/Heimer/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple mind map, diagram, and note-taking tool

LICENSE=	CC-BY-SA-3.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang qt:5
USE_QT=		core gui network svg widgets xml buildtools_build \
		linguisttools_build qmake_build testlib_build
TEST_TARGET=	test

PLIST_FILES=	bin/heimer \
		share/applications/heimer.desktop \
		share/icons/hicolor/256x256/apps/heimer.png \
		share/metainfo/heimer.appdata.xml \
		share/pixmaps/heimer.png

PORTDOCS=	README.md
PORTEXAMPLES=	examples/*.alz

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_PLIST_FILES=	${EXAMPLESDIR}/Company.alz \
			${EXAMPLESDIR}/Family.alz \
			${EXAMPLESDIR}/Heimer.alz \
			${EXAMPLESDIR}/Large.alz

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/heimer

.include <bsd.port.mk>
