# New ports collection makefile for:	xjtext
# Date created:		8 July 2000
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	xjtext
PORTVERSION=	1.3
PORTREVISION=	8
CATEGORIES=	japanese
MASTER_SITES=	http://plaza.harmonix.ne.jp/~onizuka/
DISTNAME=	XJTEXT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text viewer for Japanese vertical writings

USE_BISON=	build
USE_GNOME=	imlib

SUB_FILES=	pkg-message
PLIST_FILES=	bin/xjtext
PORTDOCS=	README.txt
PORTEXAMPLES=	FSS README YAMA Ao.png Back2.png Brown.png Royal.png Royal2.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjtext ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
