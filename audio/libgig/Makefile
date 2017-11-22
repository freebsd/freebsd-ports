# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	libgig
DISTVERSION=	4.0.0
CATEGORIES=	audio
MASTER_SITES=	SF/qsampler/${PORTNAME}/${PORTVERSION} \
		http://download.linuxsampler.org/packages/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gigasampler file loader library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/libgig
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
