# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	libgig
PORTVERSION=	3.3.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/qsampler/${PORTNAME}/${PORTVERSION} \
		http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gigasampler file loader library

LICENSE=	GPLv2

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_BZIP2=	yes
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
