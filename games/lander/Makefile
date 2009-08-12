# New ports collection makefile for:	lander
# Date created:		21 Feb 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lander
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lunar Lander clone

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		boost_filesystem.4:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_SDL=	sdl image mixer
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.2+

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-boost="${LOCALBASE}" \
		--with-boost-filesystem=boost_filesystem

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/LIBS=/ s|-lSDL_|`${SDL_CONFIG} --libs` &|' \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
