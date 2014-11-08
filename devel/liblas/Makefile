# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblas
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libLAS/libLAS/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library For Reading And Writing LAS-Format Data

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs

LICENSE=	BSD2CLAUSE

CONFLICTS=	liblas12-1.2*

USES=		cmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libLAS-${PORTVERSION}

.include <bsd.port.mk>
