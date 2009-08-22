# New ports collection makefile for:	love
# Date created:		01 Aug 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	love
DISTVERSION=	0.5-0
PORTREVISION=	4
CATEGORIES=	games devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.5-0

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		physfs.1:${PORTSDIR}/devel/physfs \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
USE_GL=		gl glu
USE_LUA=	5.1+
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LUA_INCDIR} `${SDL_CONFIG} --cflags`" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}"
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --libdir=${PREFIX}/lib

PLIST_FILES=	bin/love

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|ILvoid|void|' ${WRKSRC}/src/opengl/Image.cpp \
		${WRKSRC}/src/opengl/love_opengl.cpp
	@${REINPLACE_CMD} -e '/^prefix=/ d; /^bindir=/ d; /^libdir=/ d' \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
