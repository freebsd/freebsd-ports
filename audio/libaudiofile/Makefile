PORTNAME=	libaudiofile
PORTVERSION=	0.3.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	GNOME/sources/${PORTNAME:S/lib//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	audiofile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound library for SGI audio file

LICENSE=	LGPL21

LIB_DEPENDS=	libFLAC.so:audio/flac

CONFLICTS=	osalp-0.7.*

USES=		cpe pathfix pkgconfig tar:xz libtool
CPE_PRODUCT=	audiofile

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudiofile.so.1

.include <bsd.port.mk>
