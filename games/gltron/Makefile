# New ports collection makefile for:	gltron
# Date created:				24 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gltron
PORTVERSION=	0.70
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A 3D worm game for two players for X Window System

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GL=		gl
USE_SDL=	sdl sound
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-warn

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_SDL_NET)
USE_SDL+=	net
CONFIGURE_ARGS+=	--enable-network
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-D|CFLAGS="$$CFLAGS -D|g ; \
		 s|-O$$enable_optimize||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^AM_CFLAGS|INCLUDES|g ; \
		 s|^AM_CXXFLAGS|INCLUDES|g ; \
		 s|-ansi -pedantic||g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
