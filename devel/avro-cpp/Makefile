# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.7.4
CATEGORIES=	devel
MASTER_SITES=	http://www.sai.msu.su/apache/${PORTNAME}/${PORTNAME}-${PORTVERSION}/ \
		APACHE
MASTER_SITE_SUBDIR=	${PORTNAME}/stable
PKGNAMESUFFIX=	-cpp
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Data serialization system for C++

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

USES=		cmake
USE_LDCONFIG=	yes
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/lang/c++

.include <bsd.port.mk>
