PORTNAME=	spider
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/solitaires
DISTNAME=	${PORTNAME}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Challenging double decked solitaire game

LICENSE=	Spider
LICENSE_GROUPS=	BSD
LICENSE_NAME=	Spider license
LICENSE_FILE=	${WRKSRC}/copyright.h
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		imake tar:Z xorg
USE_XORG=	x11 xext xaw xmu xt sm ice xpm

INSTALL_TARGET=	install install.doc

CFLAGS+=	-Wno-error=return-type

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
