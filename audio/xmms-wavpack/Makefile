# $FreeBSD$

PORTNAME=	xmms-wavpack
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin to play WavPack files

LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack \
		libxmms.so:${PORTSDIR}/multimedia/xmms

USES=		pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/xmms/Input/libwavpack.so

.include <bsd.port.mk>
