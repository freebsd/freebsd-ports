# New ports collection makefile for:	phlipple
# Date created:		01 Nov 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phlipple
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Flipping squares will never be the same

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		GLEW.1:${PORTSDIR}/graphics/glew

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/*.c
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
