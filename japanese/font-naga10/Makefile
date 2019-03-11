# Created by: Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
# $FreeBSD$

PORTNAME=	naga10
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013391/fonts/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	knj10-${PORTVERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	10-dot Kanji font

BUILD_DEPENDS=	mkbold:x11-fonts/mkbold-mkitalic \
		bdftopcf:x11-fonts/bdftopcf

USES=		fonts
NO_ARCH=	yes
SUB_FILES=	Makefile pkg-message
MAKEFILE=	${WRKDIR}/Makefile
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
