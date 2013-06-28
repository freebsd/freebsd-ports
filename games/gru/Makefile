# Created by: HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
# $FreeBSD$

PORTNAME=	gru
PORTVERSION=	8087
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.bsddiary.net/gru/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gru makes your eyes happy

USES=		imake
USE_XORG=	x11 xext xmu xpm xaw xt sm ice

MAN1=		gru.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/ja/gru
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.jp ${DOCSDIR}
.endif

.include <bsd.port.mk>
