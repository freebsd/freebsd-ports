# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-cpp

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for Apache Avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake compiler:c++11-lang

USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	lang/c++

GH_ACCOUNT=	apache
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${AVRO_VERSION_MAJOR}.\($${AVRO_VERSION_MINOR}\)|\1|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
