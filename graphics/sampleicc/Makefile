# $FreeBSD$

PORTNAME=	sampleicc
PORTVERSION=	1.6.6
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20tar/SampleIcc-${PORTVERSION}/
DISTNAME=	SampleICC-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for reading, writing, manipulating, and applying ICC profiles

LICENSE=	ICC
LICENSE_NAME=	The ICC Software License, Version 0.2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES=	pathfix
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
