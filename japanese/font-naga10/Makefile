# Created by: Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
# $FreeBSD$

PORTNAME=	naga10
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013391/fonts/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	knj10-${PORTVERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	10-dot Kanji font

BUILD_DEPENDS=	mkbold:x11-fonts/mkbold-mkitalic \
		bdftopcf:x11-fonts/bdftopcf

USES=		fonts
FONTNAME=	misc
NO_ARCH=	yes
SUB_FILES=	Makefile pkg-install
SUB_LIST=	FONTSALIAS="${DATADIR}/fonts.alias"
MAKEFILE=	${WRKDIR}/Makefile
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s ../../../${DATADIR_REL}/*.pcf.gz .

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
