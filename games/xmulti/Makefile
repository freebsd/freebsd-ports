# Created by: Toru YANO <toru@s-fine.co.jp>
# $FreeBSD$

PORTNAME=	xmulti
PORTVERSION=	2.00b4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.denpa.org/~go/xmulti/
DISTFILES=	xmul200b4.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 mascot based on gal-game "To Heart"

WRKSRC=		${WRKDIR}/xmulti200beta4

USES=		imake
USE_XORG=	x11 xext xaw xmu xt xpm sm ice

DOCSDIR=	${PREFIX}/share/doc/ja/{PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in MODULE.jp README.jp STYLESHEET.jp XMULTI.jp
	${INSTALL_MAN} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
