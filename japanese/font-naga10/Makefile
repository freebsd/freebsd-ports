# Created by: Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>

PORTNAME=	naga10
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013391/fonts/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	knj10-${PORTVERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	10-dot Kanji font

LICENSE=	NOTPARTIAL
LICENSE_NAME=	Whole not partial
LICENSE_TEXT=	Free redistribution of the whole package allowed, not partial
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	mkbold:x11-fonts/mkbold-mkitalic \
		bdftopcf:x11-fonts/bdftopcf

USES=		fonts
FONTPATHSPEC=	${FONTNAME}:unscaled:pri=60
NO_ARCH=	yes
SUB_FILES=	Makefile
MAKEFILE=	${WRKDIR}/Makefile
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
