# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	seexpr
DISTVERSIONPREFIX=	v
PORTVERSION=	2.11
PORTREVISION=	5
CATEGORIES=	graphics math

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Embeddable expression evaluation language

LICENSE=	APACHE20

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USE_GITHUB=	yes
GH_ACCOUNT=	wdas
GH_PROJECT=	SeExpr

USES=		bison cmake compiler:c++0x pyqt:4 python:2.7 qt:4
USE_PYQT=	gui_build sip_build
USE_QT=		moc_build qmake_build rcc_build uic_build gui opengl
BINARY_ALIAS=	sip=sip-${PYTHON_VER}

MAKE_JOBS_UNSAFE=	yes	# https://github.com/wdas/seexpr/issues/40

CXXFLAGS+=	-I${LOCALBASE}/include

.if ${MACHINE_CPU:Msse41}
CMAKE_ARGS+=	-DUSE_SSE41:BOOL=ON
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<alloca\.h>/d' ${WRKSRC}/src/SeExpr/SePlatform.h
	@${REINPLACE_CMD} -e 's, "dl",,' ${WRKSRC}/src/SeExpr/CMakeLists.txt

.include <bsd.port.mk>
