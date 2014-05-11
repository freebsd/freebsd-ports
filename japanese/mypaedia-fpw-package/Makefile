# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaedia-fpw-package
PORTVERSION=	1.0.7
PORTREVISION=	6
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/mypaedia/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supplement file to use "mypaedia" on lookup

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		timidity:${PORTSDIR}/audio/timidity++ \
		xanim:${PORTSDIR}/multimedia/xanim \
		display:${PORTSDIR}/graphics/ImageMagick

NO_BUILD=	yes
PLIST_SUB=	PKGNAME=${PKGNAME}

PKG_DIR=	${STAGEDIR}${PREFIX}/share/dict/lookup-package

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${PKG_DIR}
	${INSTALL_DATA} ${WRKSRC}/mypaedia-fpw.el ${PKG_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extract-mypaedia.pl ${PKG_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README.TXT \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
