# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qcad
PORTVERSION=	3.22.0.12
PORTREVISION=	1
DISTVERSIONPREFIX=	v
#PORTREVISION=
CATEGORIES=	cad
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

LICENSE=	GPLv3

.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=	ld: error: relocation R_386_PC32 cannot be used against symbol ON_GetPointListBoundingBox
.endif

BUILD_DEPENDS=	bash:shells/bash	\
		${LOCALBASE}/lib/libopenNURBS.a:graphics/opennurbs

MAKE_JOBS_UNSAFE=yes

USES=		compiler:c++11-lang gl gmake qmake qt:5
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		buildtools qmake_build \
		designer gui help imageformats network opengl script \
		scripttools sql svg uitools xml xmlpatterns webkit
USE_GL=		glu

DESKTOP_ENTRIES="QCad"	\
		"" \
		"${DATADIR}/scripts/qcad_icon.png"	\
		"${PREFIX}/bin/qcad-bin"	\
		""	\
		true

.if defined(WITH_DEBUG)
RESDIR=		${WRKSRC}/debug
.else
RESDIR=		${WRKSRC}/release
.endif

SHRLIBS=	qcadcore qcadecmaapi qcadentity qcadgrid qcadgui qcadoperations	\
		qcadsnap qcadspatialindex qcadstemmer spatialindexnavel
STALIBS=	dxflib stemmer
SHRDIR=		fonts libraries linetypes patterns plugins scripts themes ts
#QSCRIPTS should not be installed to avoid conflicts with texlive-base
QSCRIPTS=	bbox dwg2bmp dwg2pdf dwg2svg

OPTIONS_DEFINE=	EXAMPLES

CFLAGS_i386= -fPIC
CXXFLAGS_i386= -fPIC

pre-configure:
	${MKDIR} ${WRKSRC}/src/3rdparty/qt-labs-qtscriptgenerator-5.13.2
	${CP} ${WRKSRC}/src/3rdparty/qt-labs-qtscriptgenerator-5.13.0/qt-labs-qtscriptgenerator-5.13.0.pro \
	      ${WRKSRC}/src/3rdparty/qt-labs-qtscriptgenerator-5.13.2/qt-labs-qtscriptgenerator-5.13.2.pro
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"	\
		${WRKSRC}/src/core/RS.cpp
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"	\
		${WRKSRC}/src/core/RSettings.cpp

do-install:
	${INSTALL_PROGRAM} ${RESDIR}/qcad-bin ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf qcad-bin ${STAGEDIR}${PREFIX}/bin/qcad
.for lib in ${SHRLIBS:C|^|lib|:C|$|.so|}
	${INSTALL_LIB} ${RESDIR}/${lib} ${STAGEDIR}${PREFIX}/lib/${lib}.0
	${LN} -sf ${lib}.0 ${STAGEDIR}${PREFIX}/lib/${lib}
.endfor
.for lib in ${STALIBS:C|^|lib|:C|$|.a|}
	${INSTALL_DATA} ${RESDIR}/${lib} ${STAGEDIR}${PREFIX}/lib/
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
.for dir in ${SHRDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
