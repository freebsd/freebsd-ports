# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	angband
PORTVERSION=	3.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games
MASTER_SITES=	http://rephial.org/downloads/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rogue-like game with color, X11 support

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

OPTIONS_DEFINE=	SDL X11 DOCS
OPTIONS_DEFAULT=X11

USES=		gmake ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_NCURSES_CONFIG=${TRUE}
CONFIGURE_ARGS=	--localstatedir=/var

CPPFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-L${NCURSESLIB} -lncursesw

DOCS_BUILD_DEPENDS=	rst2html:textproc/py-docutils

SDL_USE=		SDL=image,mixer,ttf,sdl
SDL_CONFIGURE_ENABLE=	sdl

X11_USE=		XORG=sm,x11
X11_RUN_DEPENDS=	xorg-fonts-miscbitmaps>=0:x11-fonts/xorg-fonts-miscbitmaps
X11_CONFIGURE_ENABLE=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wno-missing-field-initializers || ; \
		 s|/games$$|/bin|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|.SILENT:||' ${WRKSRC}/mk/buildsys.mk.in
	@${REINPLACE_CMD} -e \
		's|-O0||' ${WRKSRC}/src/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/angband
.for i in apex save user
	@${MKDIR} ${STAGEDIR}${DATADIR}/${i}
.endfor

.include <bsd.port.mk>
