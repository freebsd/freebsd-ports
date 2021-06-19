# Created by: ijliao

PORTNAME=	csmash
PORTVERSION=	0.6.6
PORTREVISION=	22
CATEGORIES=	games
MASTER_SITES=	SF/cannonsmash/CannonSmash/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D tabletennis game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gettext gl gmake gnome pkgconfig sdl
USE_SDL=	image mixer sdl
USE_GL=		yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/SDL
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/games/|/|g'
	@${REINPLACE_CMD} -e 's|BallView::||' ${WRKSRC}/BallView.h
	@${REINPLACE_CMD} -e 's|== 3|>= 3|' ${WRKSRC}/matrix

.include <bsd.port.mk>
