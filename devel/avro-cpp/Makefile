# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.7.3
CATEGORIES=	devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	${PORTNAME}/stable
PKGNAMESUFFIX=	-cpp
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Data serialization system for C++

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/lang/c++

.include <bsd.port.mk>
