PORTNAME=	qcad
PORTVERSION=	3.32.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	cad
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system
WWW=		https://www.ribbonsoft.com/qcad.html

LICENSE=	GPLv3

BROKEN_i386=	doesn't build on pkg builder

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libOpenNURBS.so:graphics/opennurbs	\
		libqtjsapi.so:cad/qtjsapi	\
		libcups.so:print/cups

USES=		cmake compiler:c++17-lang gl localbase:ldflags qt:6
USE_CXXSTD=	c++17

USE_GITHUB=	yes

CMAKE_ON=	BUILD_QT6
USE_QT=		5compat base declarative svg tools
USE_GL=		opengl
USE_LDCONFIG=	yes

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

SHRLIBS=	qcadcore qcadentity qcadgrid qcadgui qcadoperations	\
		qcadsnap qcadspatialindex qcadstemmer spatialindexnavel
STALIBS=	dxflib stemmer
SHRDIR=		fonts libraries linetypes patterns plugins scripts support themes ts

OPTIONS_DEFINE=	EXAMPLES

CFLAGS+=	-DON_SIZEOF_WCHAR_T=4 -fPIC
LDFLAGS+=	-lexecinfo
LDFLAGS_i386=	-Wl,-z,notext

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "powerpc" && ${ARCH} != powerpc64
CFLAGS+=	-DON_LITTLE_ENDIAN
.else
CFLAGS+=	-DON_BIG_ENDIAN
.endif

pre-configure:
	${MKDIR} ${WRKSRC}/src/3rdparty/qt-labs-qtscriptgenerator-${_QT_VERSION}
	${CP} ${WRKSRC}/src/3rdparty/qt-labs-qtscriptgenerator-5.13.2/qt-labs-qtscriptgenerator-5.13.2.pro \
		${WRKSRC}/src/3rdparty/qt-labs-qtscriptgenerator-${_QT_VERSION}/qt-labs-qtscriptgenerator-${_QT_VERSION}.pro
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"	\
		${WRKSRC}/src/core/RS.cpp
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"	\
		${WRKSRC}/src/core/RSettings.cpp

do-install:
	${INSTALL_PROGRAM} ${RESDIR}/qcad ${STAGEDIR}${PREFIX}/bin/
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

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
