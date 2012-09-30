# Created by: FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
# $FreeBSD$

PORTNAME=	xbloody
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.kazu.kz/freebsd/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Knife on X

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
USE_XORG=	x11 xext xt sm ice

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xbloody
	@${INSTALL_DATA} ${WRKSRC}/README.sjis ${PREFIX}/share/doc/xbloody
.endif

.include <bsd.port.post.mk>
