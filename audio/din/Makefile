PORTNAME=	din
PORTVERSION=	59
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://dinisnoise.org/files/

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Open source, cross-platform sound synthesizer
WWW=		https://dinisnoise.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libboost_thread.so:devel/boost-libs \
		libjack.so:audio/jack

USES=		autoreconf gl gnome sdl tcl:86+ xorg
USE_GL=		gl
USE_SDL=	sdl

GNU_CONFIGURE=	yes

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	ALSA JACK
OPTIONS_DEFAULT=	JACK

JACK_DESC=	Uses JACK sound server
ALSA_DESC=	Uses ALSA sound server

ALSA_CXXFLAGS+=	-D__LINUX_ALSA__
JACK_CXXFLAGS+=	-D__UNIX_JACK__

CXXFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl${TCL_VER} -Wno-register
LIBS+=		-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER} -lthr -ljack

.include <bsd.port.mk>
