# New ports collection makefile for:	xjtext
# Date created:		8 July 2000
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	xjtext
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	http://plaza.harmonix.ne.jp/~onizuka/
DISTNAME=	XJTEXT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text viewer for Japanese vertical writings

USE_BISON=	yes
USE_GNOME=	imlib

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjtext ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
.for file in FSS README YAMA Ao.png Back2.png Brown.png Royal.png Royal2.png
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
