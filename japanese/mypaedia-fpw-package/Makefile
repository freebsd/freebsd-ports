# New ports collection makefile for:	mypaedia-fpw-package
# Date created:		00/04/24
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mypaedia-fpw-package
PORTVERSION=	1.0.5
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/mypaedia/

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		timidity:${PORTSDIR}/audio/timidity++ \
		xanim:${PORTSDIR}/graphics/xanim
# This suhould build-depend on the next port, but it depends on non-japanized GS :-<
#		display:${PORTSDIR}/graphics/ImageMagick

NO_BUILD=	yes
PLIST_SUB=	PKGNAME=${PKGNAME}

PKG_DIR=	${PREFIX}/share/dict/lookup-package
PORT_DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

do-install:
	${MKDIR} ${PKG_DIR}
	${INSTALL_DATA} ${WRKSRC}/mypaedia-fpw.el ${PKG_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extract-mypaedia.pl ${PKG_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORT_DOCDIR}
.for file in ChangeLog README.TXT
	${INSTALL_DATA} ${WRKSRC}/${file} ${PORT_DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
