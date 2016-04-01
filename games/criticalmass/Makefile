# Created by: nbm
# $FreeBSD$

PORTNAME=	criticalmass
PORTVERSION=	1.0.2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Critical%20Mass/${PORTVERSION}
DISTNAME=	CriticalMass-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL/OpenGL space shoot'em up game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png

USES=		dos2unix tar:bzip2
DOS2UNIX_FILES=	tinyxml/*.cpp tinyxml/*.h
USE_XORG=	x11
USE_GL=		gl
USE_SDL=	image mixer sdl
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimize

CPPFLAGS+=	$$(libpng-config --I_opts) $$(curl-config --cflags) \
		-I${LOCALBASE}/include
LDFLAGS+=	$$(libpng-config --L_opts) $$(curl-config --libs) \
		-L${LOCALBASE}/lib

CONFLICTS=	shaaft-[0-9]*

PLIST_FILES=	bin/Packer \
		bin/critter \
		man/man6/critter.6.gz \
		share/Critical_Mass/lg-criti.xm \
		share/Critical_Mass/resource.dat
PLIST_DIRS=	share/Critical_Mass

DESKTOP_ENTRIES="CriticallMass" "" "" "critter" "" ""

post-patch:
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e \
		's| curl|| ; \
		 s|^CXXFLAGS|#CXXFLAGS| ; \
		 s|-lSDL | | ; \
		 s|sdl-config|${SDL_CONFIG:T}| ; \
		 s|-L/usr/local/lib -L/usr/X11R6/lib|| ; \
		 s|-I/usr/X11R6/include|| ; \
		 s|-lpng12|-lpng|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s| curl||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|../curl/lib/libcurl.a||' ${WRKSRC}/game/Makefile.in
	@${REINPLACE_CMD} -e 's|and def|\&\& def|g' ${WRKSRC}/utils/OSName.hpp

.include <bsd.port.mk>
