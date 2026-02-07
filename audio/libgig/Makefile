PORTNAME=	libgig
DISTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/ # dead?: SF/qsampler/${PORTNAME}/${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gigasampler file loader library
WWW=		https://www.linuxsampler.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libuuid.so:misc/libuuid

USES=		compiler:c++11-lib gmake cpe libtool localbase pkgconfig tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/libgig

CPE_VENDOR=	linuxsampler

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
