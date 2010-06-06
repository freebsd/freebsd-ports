# New ports collection makefile for:	bos
# Date created:				14 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	boswars
PORTVERSION=	2.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://boswars.org:8001/bos/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A real-time strategy game

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		vorbis.4:${PORTSDIR}/audio/libvorbis

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
CPPPATH+=	${LOCALBASE}/include
LIBPATH+=	${LOCALBASE}/lib
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-fomit-frame-pointer -fexpensive-optimizations -ffast-math
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for f in campaigns graphics intro languages maps scripts sounds units
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
