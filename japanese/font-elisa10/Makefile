# $FreeBSD$

PORTNAME=	elisa10
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.wheel.gr.jp/~dai/software/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	elisau10

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Elisa 10-dot Kanji font

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

USES=		fonts tar:tgz
FONTNAME=	misc
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	Makefile pkg-install
SUB_LIST=	BDFTOPCF_CMD="${LOCALBASE}/bin/bdftopcf" \
		GZIP_CMD="${GZIP_CMD}" \
		FONTSALIAS="${DATADIR}/fonts.alias"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PORTDOCS=	elisau10.doc hosoku.txt
PLIST_FILES=	%%DATADIR%%/elisau10.pcf.gz \
		%%DATADIR%%/fonts.alias \
		%%FONTSDIR%%/elisau10.pcf.gz

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s ../../../${DATADIR_REL}/*.pcf.gz .
	${INSTALL_DATA} ${WRKDIR}/fonts.alias ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
