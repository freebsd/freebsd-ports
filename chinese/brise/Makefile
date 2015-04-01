# $FreeBSD$

PORTNAME=	brise
PORTVERSION=	0.32
CATEGORIES=	chinese textproc
MASTER_SITES=	http://github.com/lotem/brise/archive/brise-${DISTVERSION}.tar.gz?dummy=/
DISTNAME=	${PORTNAME}-brise-${DISTVERSION}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Rime Schema Repository

LICENSE=	GPLv3

BUILD_DEPENDS=	rime_deployer:${PORTSDIR}/chinese/librime

USES=		gmake

MAKE_ARGS+=	RIME_DATA_DIR=${DATADIR}

.include <bsd.port.mk>
