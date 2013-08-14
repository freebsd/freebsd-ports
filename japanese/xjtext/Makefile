# Created by: sada
# $FreeBSD$

PORTNAME=	xjtext
PORTVERSION=	1.3
PORTREVISION=	11
CATEGORIES=	japanese
MASTER_SITES=	http://plaza.harmonix.ne.jp/~onizuka/
DISTNAME=	XJTEXT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text viewer for Japanese vertical writings

USES=		bison
USE_GNOME=	imlib

SUB_FILES=	pkg-message

PORTDOCS=	README.txt
PORTEXAMPLES=	FSS README YAMA Ao.png Back2.png Brown.png Royal.png Royal2.png
PLIST_FILES=	bin/xjtext

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjtext ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
