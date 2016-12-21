# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	puzzles
PORTVERSION=	20161217
CATEGORIES=	games
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/puzzles/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	sgt-
DISTNAME=	${PORTNAME}-${PORTVERSION}.${COMMITHASH}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simon Tatham's Portable Puzzle Collection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

COMMITHASH=	0b34887

USES=		autoreconf gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=sgt-
INSTALL_TARGET=	install-strip

PUZZLE_LIST=	blackbox bridges cube dominosa fifteen filling flip \
		flood galaxies guess inertia keen lightup loopy magnets map \
		mines net netslide palisade pattern pearl pegs range rect \
		samegame signpost singles sixteen slant solo tents towers \
		tracks twiddle undead unequal unruly untangle

.for f in ${PUZZLE_LIST}
PLIST_FILES+=	bin/sgt-${f}
DESKTOP_FILES_PLIST_FILES+=\
		share/pixmaps/sgt-${f}.png
DESKTOP_FILES_DESKTOP_ENTRIES+=\
		"${f}" \
		"${f} puzzle game" \
		"sgt-${f}" \
		"sgt-${f}" \
		"Game;LogicGame;" \
		""
.endfor

OPTIONS_DEFINE=	DESKTOP_FILES
OPTIONS_DEFAULT=DESKTOP_FILES GTK2
OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3

DESKTOP_FILES_DESC=	Install menu entries (lots of them)

GTK_DESC=		Gtk version
GTK2_CONFIGURE_ON=	--with-gtk=2
GTK2_USE=		GNOME=gtk20
GTK3_CONFIGURE_ON=	--with-gtk=3
GTK3_USE=		GNOME=gtk30

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure.ac \
		${WRKSRC}/configure

post-install-DESKTOP_FILES-on:
.for f in ${PUZZLE_LIST}
	${INSTALL_DATA} ${WRKSRC}/icons/${f}-48d24.png ${STAGEDIR}${PREFIX}/share/pixmaps/sgt-${f}.png
.endfor

.include <bsd.port.mk>
