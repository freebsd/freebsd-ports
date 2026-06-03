PORTNAME=	blender
DISTVERSION=	5.0
CATEGORIES=	graphics
MASTER_SITES=	https://docs.blender.org/manual/en/${PORTVERSION}/
PKGNAMESUFFIX=	-doc
DISTFILES=	blender_manual_html.zip blender_manual_epub.zip
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Blender Documentation
WWW=		https://docs.blender.org/

LICENSE=	CC-BY-SA-4.0

USES=		zip

EXTRACT_BEFORE_ARGS=	-qo \
			-x *.html/_sources \
			-x *.epub/[a-zM_0-9.]*

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
NO_WRKSUBDIR=	yes
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	EPUB HTML
OPTIONS_MULTI=		DOCS
OPTIONS_MULTI_DOCS=	EPUB HTML
OPTIONS_EXCLUDE=	DOCS
EPUB_DESC=		Install manual in an e-book format (EPUB)
HTML_DESC=		Install manual as web pages (HTML)

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}

do-install-EPUB-on:
	${INSTALL_DATA} ${WRKSRC}/*.epub/*.epub ${STAGEDIR}${DOCSDIR}

do-install-HTML-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} *.html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
