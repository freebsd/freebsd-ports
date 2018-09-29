# $FreeBSD$

PORTNAME=	opus-tools
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	MOZILLA/opus

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Encode, inspect, and decode Opus files

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libogg.so:audio/libogg \
		libopusenc.so:audio/libopusenc \
		libopus.so:audio/opus \
		libopusfile.so:audio/opusfile

USES=		pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode

.include <bsd.port.mk>
