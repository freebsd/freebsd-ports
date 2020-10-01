# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	seexpr
PORTVERSION=	3.4.4.0
CATEGORIES=	graphics math
MASTER_SITES=	https://download.kde.org/stable/${PORTNAME}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Embeddable expression evaluation language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		bison cmake compiler:c++14-lang gl qt:5
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_QT=		buildtools_build qmake_build core gui opengl widgets

MAKE_JOBS_UNSAFE=	yes	# https://github.com/wdas/seexpr/issues/40

OPTIONS_DEFINE=	ANIMCURVE DEEPWATER LLVM NLS PYTHON
OPTIONS_DEFAULT=	DEEPWATER
OPTIONS_SUB=	yes

ANIMCURVE_DESC=	Build controls for animation curves
ANIMCURVE_CMAKE_ON=	-DENABLE_ANIMCURVE:BOOL=TRUE
ANIMCURVE_BROKEN=	error: use of undeclared identifier 'animlib'

DEEPWATER_DESC=	Build controls for deep water spectrum
DEEPWATER_CMAKE_ON=	-DENABLE_DEEPWATER:BOOL=TRUE

LLVM_DESC=		Build with LLVM ${LLVM_DEFAULT:C/.$$//} backend
LLVM_LIB_DEPENDS=	libLLVM.so:devel/llvm${LLVM_DEFAULT}
LLVM_CMAKE_OFF=		-DENABLE_LLVM_BACKEND:BOOL=FALSE

NLS_USES=		kde:5
NLS_USE=		KDE=ecm_build
NLS_CMAKE_OFF=		-DBUILD_TRANSLATIONS:BOOL=FALSE

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

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/SeExpr2/generated

.include <bsd.port.mk>
