# New ports collection makefile for:	bos
# Date created:				14 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	boswars
PORTVERSION=	2.6.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.boswars.org/dist/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martin@arp242.net
COMMENT=	A real-time strategy game

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_LUA=	5.1
USE_SDL=	sdl
USE_GL=		yes
USE_SCONS=	yes
SCONS_ARGS+=	opengl=1
CPPPATH=	${LOCALBASE}/include ${LUA_INCDIR}
LIBPATH=	${LOCALBASE}/lib ${LUA_LIBDIR}
CFLAGS+=	-DSTRATAGUS_LIB_PATH='"\"${DATADIR}\""'

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

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
