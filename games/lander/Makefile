# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lander
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lunar Lander clone

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		boost_filesystem:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_SDL=	sdl image mixer
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.2+

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-boost="${LOCALBASE}" \
		--with-boost-filesystem=boost_filesystem

PORTDOCS=	*

DESKTOP_ENTRIES="Lunar Lander" \
		"Lunar Lander clone" \
		"${DATADIR}/images/ship.png" \
		"lander" \
		"Game;ArcadeGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/LIBS=/ s|-lSDL_|`${SDL_CONFIG} --libs` &|' \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
