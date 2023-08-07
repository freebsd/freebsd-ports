PORTNAME=	supertux
PORTVERSION=	0.1.3
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	https://github.com/SuperTux/downloads/raw/master/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Side-scroller game similar to Super Mario Brothers
WWW=		http://supertuxproject.org/

USES=		gl gmake sdl tar:bzip2 xorg
USE_CXXSTD=	c++14
USE_GL=		gl
USE_SDL=	image mixer
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--disable-debug

PORTSCOUT=	limit:^0\.1

post-patch:
	@${REINPLACE_CMD} -e 's,Menu::,,' ${WRKSRC}/src/menu.h

.include <bsd.port.mk>
