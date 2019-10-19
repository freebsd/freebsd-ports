# $FreeBSD$

PORTNAME=	oidn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel(R) Open Image Denoise library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Intel(R) MKL-DNN supports x86 64 bit platforms only (oidn contains a custom version of mkl-dnn, see math/mkl-dnn)

LIB_DEPENDS=	libtbb.so:devel/tbb

USES=		cmake:noninja compiler:c++11-lang python:build
USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageDenoise
GH_TUPLE=	OpenImageDenoise:oidn-weights:f175104:w/weights \
		OpenImageDenoise:mkl-dnn:096bda1:m/mkl-dnn
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

CMAKE_ARGS+=	-DTBB_ROOT:STRING=${LOCALBASE} -DTBB_INCLUDE_DIR:STRING=${LOCALBASE}/include -DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD}

DOCSDIR=	share/doc/${GH_ACCOUNT}

.include <bsd.port.mk>
