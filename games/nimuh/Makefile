# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	nimuh
PORTVERSION=	1.02
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/Nimuh%20SRC%20%28Source%20Code%29
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game destined to improve the knowledge of Andalusia

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake
USE_SDL=	sdl image mixer
USE_GL=		gl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
