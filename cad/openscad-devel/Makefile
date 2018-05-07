# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openscad
PORTVERSION=	2018.04.19
PORTREVISION=	2
CATEGORIES=	cad
PKGNAMESUFFIX=  -devel
DIST_SUBDIR=            ${PORTNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Programmer's solid 3D CAD modeller

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:devel/boost-libs
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libCGAL.so:math/cgal \
		libqscintilla2_qt4.so:devel/qscintilla2 \
		libharfbuzz.so:print/harfbuzz \
		libopencsg.so:graphics/opencsg \
		libzip.so:archivers/libzip

CONFLICTS=	openscad

USES=		bison compiler:c++11-lang desktop-file-utils eigen:3 gettext-tools \
		pkgconfig python:run qmake shebangfix
USE_GITHUB=     yes
GH_ACCOUNT=     openscad
GH_PROJECT=     openscad
GH_TAGNAME=	179074dff8c23cbc0e651ce8463737df0006f4ca

#SHEBANG_FILES=	libraries/MCAD/get_submodules.py
USE_GL=		glu glew
USE_QT4=	corelib gui opengl moc_build uic_build rcc_build
PLIST_SUB=	PORTVERSION=${PORTVERSION}
QMAKE_ENV=	EIGENDIR=${LOCALBASE}/include/eigen3
QMAKE_ARGS+=	VERSION=${PORTVERSION} \
		CONFIG+="experimental" \
		QMAKE_LEX=${LOCALBASE}/bin/flex \
		QMAKE_YAC=${LOCALBASE}/bin/bison

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/openscad.pro

.include <bsd.port.mk>
