# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	puzzles
PORTVERSION=	r10116
CATEGORIES=	games
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/puzzles/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	sgt-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simon Tatham's Portable Puzzle Collection

LICENSE=	MIT

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--program-prefix=sgt-
INSTALL_TARGET=	install-strip

PUZZLE_LIST=	blackbox bridges cube dominosa fifteen filling flip \
		galaxies guess inertia keen lightup loopy magnets map \
		mines net netslide pattern pearl pegs range rect samegame \
		signpost singles sixteen slant solo tents towers twiddle \
		undead unequal unruly untangle

.for f in ${PUZZLE_LIST}
PLIST_FILES+=	bin/sgt-${f}
.endfor

OPTIONS_DEFINE=	DESKTOP_FILES
OPTIONS_DEFAULT=DESKTOP_FILES
DESKTOP_FILES_DESC=Install menu entries (lots of them)

.for f in ${PUZZLE_LIST}
DESKTOP_FILES_PLIST_FILES+=	share/pixmaps/sgt-${f}.png
DESKTOP_FILES_DESKTOP_ENTRIES+=\
		"${f}" \
		"${f} puzzle game" \
		"sgt-${f}" \
		"sgt-${f}" \
		"Game;LogicGame;" \
		""
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure.ac \
		${WRKSRC}/configure

post-install-DESKTOP_FILES-on:
.for f in ${PUZZLE_LIST}
	${INSTALL_DATA} ${WRKSRC}/icons/${f}-48d24.png ${STAGEDIR}${PREFIX}/share/pixmaps/sgt-${f}.png
.endfor

.include <bsd.port.mk>
