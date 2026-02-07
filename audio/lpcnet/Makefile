PORTNAME=	lpcnet
DISTVERSIONPREFIX=v
DISTVERSION=	0.5
PORTEPOCH=	1
CATEGORIES=	audio hamradio
MASTER_SITES=	https://rowetel.com/downloads/deep/:ADD
DISTFILES=	lpcnet_191005_v1.0.tgz:ADD

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Neural Net speech coding
WWW=		https://freedv.org/

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib

USE_GITHUB=	yes
GH_ACCOUNT=	drowe67
GH_PROJECT=	LPCNet

CMAKE_ARGS=	-DMACHINE_CPU:STRING="${MACHINE_CPU}" \
		-DWRKDIR:STRING=${WRKDIR} \
		-DWRKSRC:STRING=${WRKSRC}

post-extract:
	@${EXTRACT_CMD} xf ${DISTDIR}/lpcnet_191005_v1.0.tgz -C${WRKSRC}/src

.include <bsd.port.mk>
