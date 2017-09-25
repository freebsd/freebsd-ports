# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.8.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.sai.msu.su/apache/${PORTNAME}/${PORTNAME}-${PORTVERSION}/ \
		APACHE/${PORTNAME}/stable
PKGNAMESUFFIX=	-cpp
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Data serialization system for C++

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake python:build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/lang/c++

post-patch:
	@${REINPLACE_CMD} -e 's|COMMAND python|COMMAND "${PYTHON_CMD}"|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|BOOST_CHECKPOINT|BOOST_TEST_CHECKPOINT|' \
		${WRKSRC}/test/SchemaTests.cc
	@${REINPLACE_CMD} -e 's|BOOST_MESSAGE|BOOST_TEST_MESSAGE|' \
		${WRKSRC}/test/buffertest.cc

.include <bsd.port.mk>
