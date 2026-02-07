PORTNAME=	libaudiofile
PORTVERSION=	0.3.6
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	GNOME
DISTNAME=	audiofile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound library for SGI audio file
WWW=		https://www.68k.org/~michael/audiofile/

LICENSE=	LGPL21

LIB_DEPENDS=	libFLAC.so:audio/flac

CONFLICTS=	osalp-0.7.*

USES=		cpe pkgconfig tar:xz libtool
USE_CXXSTD=	c++14
CPE_PRODUCT=	audiofile
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudiofile.so.1

.include <bsd.port.mk>
