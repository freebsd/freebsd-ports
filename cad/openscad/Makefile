# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openscad
PORTVERSION=	2015.03
PORTREVISION=	25
CATEGORIES=	cad
MASTER_SITES=	http://files.openscad.org/
DISTNAME=	openscad-${PORTVERSION}.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Programmer's solid 3D CAD modeller

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:devel/boost-libs
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libCGAL.so:math/cgal \
		libqscintilla2_qt4.so:devel/qscintilla2 \
		libharfbuzz.so:print/harfbuzz \
		libopencsg.so:graphics/opencsg

CONFLICTS=      openscad-devel

USES=		bison compiler:c++11-lang desktop-file-utils eigen:3 gettext-tools \
		pkgconfig python:run qmake qt:4 shebangfix
SHEBANG_FILES=	libraries/MCAD/get_submodules.py
USE_GL=		glu glew
USE_QT=		corelib gui opengl moc_build uic_build rcc_build
PLIST_SUB=	PORTVERSION=${PORTVERSION}
QMAKE_ENV=	EIGENDIR=${LOCALBASE}/include/eigen3
QMAKE_ARGS+=	VERSION=${PORTVERSION} \
		QMAKE_LEX=${LOCALBASE}/bin/flex \
		QMAKE_YAC=${LOCALBASE}/bin/bison
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/openscad.pro

#.include <bsd.port.options.mk>
#
#.if ${ARCH} == i386
#USE_GCC=        yes
#.endif

.include <bsd.port.mk>
