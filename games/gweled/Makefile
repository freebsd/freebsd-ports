# Created by: James Earl
# $FreeBSD$

PORTNAME=	gweled
PORTVERSION=	0.7
PORTREVISION=	13
CATEGORIES=	games gnome
MASTER_SITES=	http://sebdelestaing.free.fr/gweled/Release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME version of the game called "Bejeweled" or "Diamond Mine"

LIB_DEPENDS=	libmikmod.so:${PORTSDIR}/audio/libmikmod

USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gnomehier libgnomeui librsvg2
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/var/games|${PREFIX}/share/games|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$${MKDIRPROG-mkdir}|mkdir -p|' \
		${WRKSRC}/install-sh

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/games/gweled.easy.scores
	${TOUCH} ${STAGEDIR}${PREFIX}/share/games/gweled.easy.scores.sample
	${TOUCH} ${STAGEDIR}${PREFIX}/share/games/gweled.timed.scores.sample

.include <bsd.port.mk>
