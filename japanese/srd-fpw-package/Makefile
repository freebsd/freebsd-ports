# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	srd-fpw-package
PORTVERSION=	1.0.8
PORTREVISION=	5
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/srd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supplement file for lookup to use "Random House"

RUN_DEPENDS=	display:graphics/ImageMagick
# Your PC does not have an audio card always.
#		realplay:multimedia/linux-realplayer

NO_BUILD=	yes
USES=		perl5

PKG_DIR=	${STAGEDIR}${PREFIX}/share/dict/lookup-package

PLIST_FILES=	share/dict/lookup-package/srd-fpw.el \
		share/dict/lookup-package/extract-srd.pl
PORTDOCS=	ChangeLog README.TXT

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${PKG_DIR}
	${INSTALL_DATA} ${WRKSRC}/srd-fpw.el ${PKG_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extract-srd.pl ${PKG_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
