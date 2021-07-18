# Created by: trasz <trasz@pin.if.uz.zgora.pl>

PORTNAME=	libgig
DISTVERSION=	4.3.0
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/ # dead?: SF/qsampler/${PORTNAME}/${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gigasampler file loader library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c++11-lib gmake libtool localbase pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/libgig

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
