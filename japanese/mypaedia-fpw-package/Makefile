# New ports collection makefile for:	mypaedia-fpw-package
# Date created:		00/04/24
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mypaedia-fpw-package
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/mypaedia/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A supplement file to use "mypaedia" on lookup

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		timidity:${PORTSDIR}/audio/timidity++ \
		xanim:${PORTSDIR}/multimedia/xanim \
		display:${PORTSDIR}/graphics/ImageMagick

NO_BUILD=	yes
PLIST_SUB=	PKGNAME=${PKGNAME}

PKG_DIR=	${PREFIX}/share/dict/lookup-package

do-install:
	${MKDIR} ${PKG_DIR}
	${INSTALL_DATA} ${WRKSRC}/mypaedia-fpw.el ${PKG_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extract-mypaedia.pl ${PKG_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ChangeLog README.TXT
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
