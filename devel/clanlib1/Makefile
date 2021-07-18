# Created by: Maxim Sobolev <sobomax@FreeBSD.org>

PORTNAME=	clanlib
PORTVERSION=	1.0.0
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-1.0/
PKGNAMESUFFIX=	1
DISTNAME=	ClanLib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game SDK

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libmikmod.so:audio/libmikmod \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		alias gl gmake jpeg libtool localbase:ldflags pathfix pkgconfig \
		sdl tar:tgz xorg
USE_CXXSTD=	c++98
USE_XORG=	x11 xi xxf86vm
USE_LDCONFIG=	yes
USE_SDL=	gfx
USE_GL=		gl glu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs \
		--enable-clanDisplay \
		--enable-clanGL \
		--enable-clanSDL \
		--enable-clanSound \
		--enable-clanNetwork \
		--enable-clanGUI \
		--enable-clanMikMod \
		--enable-clanVorbis \
		--enable-getaddr
INSTALL_TARGET=	install-strip

PLIST_SUB+=	VER=${PORTVERSION:R}

post-patch:
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|@perl_exec@|${PERL}|g' \
		${WRKSRC}/Documentation/Utilities/webbuilder.pl.in

.include <bsd.port.mk>
