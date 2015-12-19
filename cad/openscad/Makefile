# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openscad
PORTVERSION=	2015.03
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://files.openscad.org/
DISTNAME=	openscad-${PORTVERSION}.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Programmer's solid 3D CAD modeller

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/libdata/pkgconfig/eigen3.pc:${PORTSDIR}/math/eigen3 \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libCGAL.so:${PORTSDIR}/math/cgal \
		libqscintilla2.so:${PORTSDIR}/devel/qscintilla2 \
		libharfbuzz.so:${PORTSDIR}/print/harfbuzz \
		libopencsg.so:${PORTSDIR}/graphics/opencsg

USES=		bison compiler:c++11-lang desktop-file-utils gettext-tools pkgconfig qmake shebangfix
SHEBANG_FILES=	libraries/MCAD/get_submodules.py
USE_GL=		glu glew
USE_QT4=	corelib gui opengl moc_build uic_build rcc_build
PLIST_SUB=	PORTVERSION=${PORTVERSION}
QMAKE_ENV=	EIGENDIR=${LOCALBASE}/include/eigen3
QMAKE_ARGS+=	VERSION=${PORTVERSION} \
		QMAKE_LEX=${LOCALBASE}/bin/flex \
		QMAKE_YAC=${LOCALBASE}/bin/bison
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/openscad.pro

.include <bsd.port.mk>
