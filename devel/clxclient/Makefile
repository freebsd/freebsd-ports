PORTNAME=	clxclient
DISTVERSION=	3.9.2
CATEGORIES=	devel
MASTER_SITES=	http://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ wrapper library around the X Window System API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	clthreads>0:devel/clthreads \
		freetype2>0:print/freetype2

USES=		gmake localbase:ldflags pkgconfig tar:bz2 xorg
USE_XORG=	x11 xft
USE_LDCONFIG=	yes

ALL_TARGET=	libclxclient.so.${DISTVERSION}

CXXFLAGS+=	-I${WRKSRC}

MAKE_ARGS=	LIBDIR=${LOCALBASE}/lib

WRKSRC_SUBDIR=	source

PLIST_FILES=	include/clxclient.h \
		lib/libclxclient.so \
		lib/libclxclient.so.${DISTVERSION:R:R} \
		lib/libclxclient.so.${DISTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libclxclient.so.3.9.2

.include <bsd.port.mk>
