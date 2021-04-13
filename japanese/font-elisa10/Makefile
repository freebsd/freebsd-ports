PORTNAME=	elisa10
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.wheel.gr.jp/~dai/software/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	elisau10

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Elisa 10-dot Kanji font

LICENSE=	NOTPARTIAL-NOTCOMMERCIAL
LICENSE_NAME=	Whole, not partial, and not commercial
LICENSE_TEXT=   Free redistribution of the whole package allowed, \
		not partial, and not commercial
LICENSE_PERMS=  dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts tar:tgz
FONTPATHSPEC=	${FONTNAME}:unscaled:pri=60
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	${WRKDIR}/Makefile
SUB_FILES=	Makefile
SUB_LIST=	BDFTOPCF_CMD="${LOCALBASE}/bin/bdftopcf" \
		GZIP_CMD="${GZIP_CMD}"
PORTDOCS=	elisau10.doc hosoku.txt
PLIST_FILES=	${FONTSDIR:S,^${PREFIX}/,,}/elisau10.pcf.gz \
		${FONTSDIR:S,^${PREFIX}/,,}/fonts.alias

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
