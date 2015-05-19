# Created by: James Earl
# $FreeBSD$

PORTNAME=	gweled
PORTVERSION=	0.9.1
CATEGORIES=	games gnome
MASTER_SITES=	http://launchpad.net/gweled/trunk/${PORTVERSION}/+download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME version of the game called "Bejeweled" or "Diamond Mine"

BROKEN=		Uses unknown GNOME component gnomehier
DEPRECATED=	Broken since update to gnome3
EXPIRATION_DATE=	2015-06-02

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmikmod.so:${PORTSDIR}/audio/libmikmod

USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeui librsvg2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
