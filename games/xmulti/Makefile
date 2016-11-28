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

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

OPTIONS_DEFINE=	DOCS

BROKEN_aarch64=	Fails to build: fatal error: machine/limits.h file not found

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in MODULE.jp README.jp STYLESHEET.jp XMULTI.jp
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
