PORTNAME=	libaudiofile
PORTVERSION=	0.3.6
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	GNOME/sources/${PORTNAME:S/lib//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	audiofile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound library for SGI audio file
WWW=		https://www.68k.org/~michael/audiofile/

LICENSE=	LGPL21

LIB_DEPENDS=	libFLAC.so:audio/flac

CONFLICTS=	osalp-0.7.*

USES=		cpe pathfix pkgconfig tar:xz libtool
USE_CXXSTD=	c++14
CPE_PRODUCT=	audiofile
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudiofile.so.1

.include <bsd.port.mk>
