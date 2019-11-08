# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	nimuh
PORTVERSION=	1.02
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/Nimuh%20SRC%20%28Source%20Code%29
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game destined to improve the knowledge of Andalusia

BROKEN=		unfetchable

LICENSE=	CC-BY-NC-SA-2.0

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gl gmake localbase sdl
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++98
USE_SDL=	sdl image mixer
USE_GL=		gl glu

DATA_WRKSRC=	${WRKDIR}/${PORTNAME}-data-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/ s|-lSDL_[a-z]*|& $${SDL_LIBS}|' ${WRKSRC}/configure

post-configure:
	@cd ${DATA_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}

post-install:
	@cd ${DATA_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
