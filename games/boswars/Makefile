# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	boswars
PORTVERSION=	2.6.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.boswars.org/dist/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martin@arp242.net
COMMENT=	Futuristic real-time strategy game

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		theora:${PORTSDIR}/multimedia/libtheora \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_LUA=	5.1
USE_SDL=	sdl
USE_GL=		yes
USE_SCONS=	yes
SCONS_ARGS+=	opengl=1
CPPPATH=	${LOCALBASE}/include ${LUA_INCDIR}
LIBPATH=	${LOCALBASE}/lib ${LUA_LIBDIR}
CFLAGS+=	-DSTRATAGUS_LIB_PATH='"\"${DATADIR}\""'

DESKTOP_ENTRIES=	"Bos Wars" "${COMMENT}" "" \
			"boswars" "Game;StrategyGame;" false

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '\
		s|-pthread|${PTHREAD_LIBS}|g; \
		s|/usr/local|${LOCALBASE}|g; \
		s|lua51|lua-${LUA_VER}|g;' \
	${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for f in campaigns graphics intro languages maps patches scripts sounds units
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.txt ${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
