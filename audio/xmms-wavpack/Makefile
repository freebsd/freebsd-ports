# $FreeBSD$

PORTNAME=	xmms-wavpack
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin to play WavPack files

LIB_DEPENDS=	wavpack.2:${PORTSDIR}/audio/wavpack \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${RM} ${PREFIX}/lib/xmms/Input/libwavpack.la

.include <bsd.port.mk>
