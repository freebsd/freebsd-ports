# New ports collection makefile for:	zatacka
# Date created:		26 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	zatacka
PORTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Nibbles-like multiplayer game

USE_SDL=	sdl ttf image
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|__linux__|__FreeBSD__|; s|\[30\]|[PATH_MAX]|' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
