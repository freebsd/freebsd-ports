# New ports collection makefile for:	srd-fpw-package
# Date created:		00/06/14
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	srd-fpw-package
PORTVERSION=	1.0.1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/srd-fpw/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	display:${PORTSDIR}/graphics/ImageMagick
# Your PC does not have an audio card always.
#		realplay:${PORTSDIR}/audio/linux-realplayer

NO_BUILD=	yes
PLIST_SUB=	PKGNAME=${PKGNAME}

PKG_DIR=	${PREFIX}/share/dict/lookup-package
PORT_DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

do-install:
	${MKDIR} ${PKG_DIR}
	${INSTALL_DATA} ${WRKSRC}/srd-fpw.el ${PKG_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extract.pl ${PKG_DIR}/srd-fpw.pl
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORT_DOCDIR}
.for file in ChangeLog README.TXT
	${INSTALL_DATA} ${WRKSRC}/${file} ${PORT_DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
