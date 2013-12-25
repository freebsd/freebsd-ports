# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
PORTVERSION=	0.7.2
PORTREVISION=	3
CATEGORIES=	devel games
MASTER_SITES=	http://cdn.bitbucket.org/rude/love/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	07
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LIB_DEPENDS=	libIL.so:${PORTSDIR}/graphics/devil \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libmpg123.so:${PORTSDIR}/audio/mpg123 \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libphysfs.so:${PORTSDIR}/devel/physfs \
		libfreetype.so:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

PORTSCOUT=	limit:^0\.7\.

USES=		gmake openal
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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
