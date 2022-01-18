# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	laszip
DISTVERSION=	3.4.3
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/LASzip/LASzip/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Library for lossless LAS compression

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++0x tar:bz2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
