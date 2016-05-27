# $FreeBSD$

PORTNAME=	brise
PORTVERSION=	0.35
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	chinese textproc

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Rime Schema Repository

LICENSE=	GPLv3

BUILD_DEPENDS=	rime_deployer:chinese/librime

BROKEN_FreeBSD_9=	does not build (segmentation fault)

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	rime

MAKE_ARGS+=	RIME_DATA_DIR=${DATADIR}

.include <bsd.port.mk>
