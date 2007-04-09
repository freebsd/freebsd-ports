# New ports collection makefile for:	bos
# Date created:				14 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	boswars
PORTVERSION=	2.3
CATEGORIES=	games
MASTER_SITES=	http://www.boswars.org/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A real-time strategy game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		theora.2:${PORTSDIR}/multimedia/libtheora \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_LUA=	5.0
USE_SDL=	sdl
USE_SCONS=	yes
CPPPATH=	${LOCALBASE}/include ${LUA_INCDIR}
LIBPATH=	${LOCALBASE}/lib ${LUA_LIBDIR}
CFLAGS+=	-DSTRATAGUS_LIB_PATH='"\"${DATADIR}\""'

OPTIONS=	GL "Enable OpenGL support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GL)
USE_GL=		yes
SCONS_ARGS+=	opengl=1
CPPPATH+=	${X11BASE}/include
LIBPATH+=	${X11BASE}/lib
.endif

.if !defined(WITH_OPTIMIZED_CFLAGS)
SCONS_ARGS+=	optimized_cflags=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for f in campaigns graphics languages maps scripts sounds units video
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
