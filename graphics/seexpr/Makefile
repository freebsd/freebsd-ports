# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	seexpr
PORTVERSION=	3.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics math

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Embeddable expression evaluation language

LICENSE=	APACHE20

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	wdas
GH_PROJECT=	SeExpr

USES=		bison cmake compiler:c++11-lang gl qt:5
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_QT=		buildtools_build qmake_build core gui opengl widgets

MAKE_JOBS_UNSAFE=	yes	# https://github.com/wdas/seexpr/issues/40

OPTIONS_DEFINE=	LLVM PYTHON
OPTIONS_SUB=	yes

LLVM_DESC=		Build with LLVM ${LLVM_DEFAULT:C/.$$//} backend
LLVM_LIB_DEPENDS=	libLLVM.so:devel/llvm${LLVM_DEFAULT}
LLVM_CMAKE_OFF=		-DENABLE_LLVM_BACKEND:BOOL=FALSE

PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_USES=		pyqt:5 python
PYTHON_USE=		PYQT=core_build,sip_build,widgets_build
PYTHON_CMAKE_ON=	-DPYQT_SIP_DIR:STRING=${PYQT_SIPDIR}
PYTHON_CMAKE_OFF=	-DUSE_PYTHON:BOOL=FALSE

.if ! ${MACHINE_CPU:Msse41}
CMAKE_ARGS+=	-DENABLE_SSE4:BOOL=FALSE
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<alloca\.h>/d' ${WRKSRC}/src/SeExpr2/Platform.h
	@${REINPLACE_CMD} -e '/pkgconfig/s/share/libdata/' \
		${WRKSRC}/CMakeLists.txt
.if !defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's/-g //' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
