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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDESKTOP_FILES}
. for f in ${PUZZLE_LIST}
PLIST_FILES+=	share/pixmaps/sgt-${f}.png

DESKTOP_ENTRIES+=\
		"${f}" \
		"${f} puzzle game" \
		"sgt-${f}" \
		"sgt-${f}" \
		"Game;LogicGame;" \
		""
. endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure.ac \
		${WRKSRC}/configure

.if ${PORT_OPTIONS:MDESKTOP_FILES}
post-install:
. for f in ${PUZZLE_LIST}
	${INSTALL_DATA} ${WRKSRC}/icons/${f}-48d24.png ${STAGEDIR}${PREFIX}/share/pixmaps/sgt-${f}.png
. endfor
.endif

.include <bsd.port.mk>
