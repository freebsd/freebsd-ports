# $FreeBSD$

PORTNAME=	elisa10
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.wheel.gr.jp/~dai/software/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	elisau10

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Elisa 10-dot Kanji font

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts tar:tgz
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	Makefile pkg-message
MAKEFILE=	${WRKDIR}/Makefile
SUB_LIST=	BDFTOPCF_CMD="${LOCALBASE}/bin/bdftopcf" \
		GZIP_CMD="${GZIP_CMD}"
PORTDOCS=	elisau10.doc hosoku.txt
PLIST_FILES=	%%FONTSDIR%%/elisau10.pcf.gz \
		%%FONTSDIR%%/fonts.alias

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
