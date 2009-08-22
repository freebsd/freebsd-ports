# New ports collection makefile for:	nimuh
# Date created:		27 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	nimuh
PORTVERSION=	1.02
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/Nimuh%20SRC%20%28Source%20Code%29
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} ${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game destined to improve the knowledge of Andalusia

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer
USE_GL=		gl

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DATA_WRKSRC=	${WRKDIR}/${PORTNAME}-data-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/ s|-lSDL_[a-z]*|& $${SDL_LIBS}|' ${WRKSRC}/configure

post-configure:
	@cd ${DATA_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-install:
	@cd ${DATA_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
