PORTNAME=	lpcnet
PORTVERSION=	20210629
CATEGORIES=	audio hamradio
MASTER_SITES=	http://rowetel.com/downloads/deep/:main \
		GH:sub
DISTFILES=	lpcnet_191005_v1.0.tgz:main \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sub

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Neural Net speech coding

LICENSE=	LGPL21

LIB_DEPENDS=	libcodec2.so:audio/codec2

USES=		cmake compiler:c++11-lib
CMAKE_ARGS+=	-DMACHINE_CPU:STRING="${MACHINE_CPU}" \
				-DWRKDIR:STRING=${WRKDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	drowe67
GH_PROJECT=	LPCNet
GH_TAGNAME=	0dc5935

.include <bsd.port.pre.mk>
.include <bsd.cpu.mk>
.include <bsd.port.post.mk>
