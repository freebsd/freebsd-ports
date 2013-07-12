# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
PORTVERSION=	0.7.2
PORTREVISION=	3
CATEGORIES=	devel games
MASTER_SITES=	http://cdn.bitbucket.org/rude/love/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LIB_DEPENDS=	IL:${PORTSDIR}/graphics/devil \
		modplug:${PORTSDIR}/audio/libmodplug \
		mpg123:${PORTSDIR}/audio/mpg123 \
		vorbisfile:${PORTSDIR}/audio/libvorbis \
		physfs:${PORTSDIR}/devel/physfs \
		freetype:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

LATEST_LINK=	${PORTNAME}07

PORTSCOUT=	limit:^0\.7\.

USE_GMAKE=	yes
USE_OPENAL=	yes
USE_SDL=	sdl mixer
USE_GL=		gl glu
USE_LUA=	5.1+
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LUA_INCDIR} `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --libdir=${PREFIX}/lib \
		--program-suffix=07
WRKSRC=		${WRKDIR}/love-HEAD
USE_DOS2UNIX=	yes

PLIST_FILES=	bin/love07

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}07
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^prefix=/ d; /^bindir=/ d; /^libdir=/ d' \
		${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
