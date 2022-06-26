# Created by: ijliao

PORTNAME=	speex
DISTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/speex/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio compression format designed for speech

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libspeexdsp.so:audio/speexdsp

USES=		cpe libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CPE_VENDOR=	xiph

.include <bsd.port.mk>
