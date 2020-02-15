# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	seexpr
PORTVERSION=	3.0.1
DISTVERSIONPREFIX=	v
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

# XXX: fix the build errors and convert to OPTIONs
CMAKE_ARGS=	-DENABLE_LLVM_BACKEND:BOOL=FALSE -DUSE_PYTHON:BOOL=FALSE

.if ! ${MACHINE_CPU:Msse41}
CMAKE_ARGS+=	-DENABLE_SSE4:BOOL=FALSE
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<alloca\.h>/d' ${WRKSRC}/src/SeExpr2/Platform.h
.if !defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's/-g //' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
