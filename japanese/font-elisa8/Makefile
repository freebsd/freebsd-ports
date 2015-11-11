# Created by: Toshihiko SHIMOKAWA <toshi@tea.forus.or.jp> & ELISA Font Project
# $FreeBSD$

PORTNAME=	elisa8
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.bsdbbq.org/~toshi/distfiles/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	elisat10

MAINTAINER=	toshi@tea.forus.or.jp
COMMENT=	8-dot Kanji font 'elisa'

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

USES=		fonts
FONTNAME=	misc
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	Makefile pkg-install
SUB_LIST=	BDFTOPCF_CMD="${LOCALBASE}/bin/bdftopcf" \
		GZIP_CMD="${GZIP_CMD}" \
		FONTSALIAS="${DATADIR}/fonts.alias"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PORTDOCS=	elisa100.doc elisat10.doc elisat10.html

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s ../../../${DATADIR_REL}/*.pcf.gz .
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
