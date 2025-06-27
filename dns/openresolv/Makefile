PORTNAME=		openresolv
DISTVERSIONPREFIX=	v
DISTVERSION=		3.17.0
CATEGORIES=		dns

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Resolvconf compatible framework for managing resolv.conf
WWW=		https://roy.marples.name/projects/openresolv/
LICENSE=	BSD2CLAUSE

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	NetworkConfiguration

GNU_CONFIGURE=	yes

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

.include <bsd.port.mk>
