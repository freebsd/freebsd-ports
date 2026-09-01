PORTNAME=	fidocadj
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.9-epsilon
PORTREVISION=	0
CATEGORIES=	cad java
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Easy to use graphical editor for electronics
WWW=		https://darwinne.github.io/FidoCadJ/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		java shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	DarwinNE
GH_PROJECT=	FidoCadJ
JAVA_VERSION=	11+

SHEBANG_FILES=	dev_tools/*

MAKEFILE=	makefile
ALL_TARGET=	createjar

ICONSDIR=	share/icons/hicolor/512x512/apps

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA=${JAVA} \
		PORTVERSION=${PORTVERSION}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	manual_en.pdf

post-patch:
	${REINPLACE_CMD} -E \
		-e 's/^(createjar:)/\1 compile/1' \
		-e 's/(^Icon=|Exec=).*/\1fidocadj/1' \
		${WRKSRC}/OSes/linux/fidocadj.desktop \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}; \
	${INSTALL_DATA} ${WRKSRC}/jar/${PORTNAME}.jar ${STAGEDIR}${DATADIR}/${PORTNAME}-${PORTVERSION}.jar
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/OSes/linux/fidocadj.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${ICONSDIR}
	${INSTALL_DATA} ${WRKSRC}/OSes/mac/icona_fidocadj.png ${STAGEDIR}${PREFIX}/${ICONSDIR}/fidocadj.png

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DOCS_DISTFILES} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
