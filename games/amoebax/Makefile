# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	amoebax
PORTVERSION=	0.2.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.emma-soft.com/games/amoebax/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cute and addictive Puyo Puyo like game

LICENSE=	GPLv2 FAL
LICENSE_COMB=	dual
LICENSE_NAME_FAL=	Free Art License, version 1.2
LICENSE_FILE_FAL=	${WRKSRC}/COPYING.LAL
LICENSE_PERMS_FAL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|datarootdir|datadir|' \
		${WRKSRC}/data/Makefile.in ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
