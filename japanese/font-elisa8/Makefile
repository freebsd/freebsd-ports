# Created by: Toshihiko SHIMOKAWA <toshi@tea.forus.or.jp> & ELISA Font Project
# $FreeBSD$

PORTNAME=	elisa8
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.bsdbbq.org/~toshi/distfiles/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	elisat10

MAINTAINER=	toshi@tea.forus.or.jp
COMMENT=	8-dot Kanji font 'elisa'

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	Makefile pkg-message
MAKEFILE=	${WRKDIR}/Makefile
SUB_LIST=	BDFTOPCF_CMD="${LOCALBASE}/bin/bdftopcf" \
		GZIP_CMD="${GZIP_CMD}"
PORTDOCS=	elisa100.doc elisat10.doc elisat10.html

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
