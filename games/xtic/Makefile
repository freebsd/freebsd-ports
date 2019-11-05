# Created by: asami
# $FreeBSD$

PORTNAME=	xtic
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X version of a simple but tricky board game

USES=		imake xorg
USE_XORG=	xaw
PLIST_FILES=	bin/xtic man/man1/xtic.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/configure.h

.include <bsd.port.mk>
