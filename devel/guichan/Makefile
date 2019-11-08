# Created by: Tobias Gion <freebsd@gionet.de>
# $FreeBSD$

PORTNAME=	guichan
PORTVERSION=	0.8.2
PORTREVISION=	14
CATEGORIES=	devel games
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/guichan/${DISTFILES}/af535d7f387e774e3197cef8023ea105/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, efficient C++ GUI library designed for games

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake pathfix libtool localbase:ldflags
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=		SDL ALLEGRO OPENGL DOCS
OPTIONS_DEFAULT=	SDL OPENGL
OPTIONS_SUB=		yes

SDL_USES=		sdl
SDL_USE=		SDL=sdl,image
SDL_CONFIGURE_ENABLE=	sdl sdlimage

ALLEGRO_DESC=		Allegro support
ALLEGRO_LIB_DEPENDS=	liballeg.so:devel/allegro
ALLEGRO_CONFIGURE_ENABLE=allegro

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_CONFIGURE_ENABLE=opengl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
