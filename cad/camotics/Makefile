PORTNAME=	CAMotics
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2-rc1
CATEGORIES=	cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	3-axis CNC GCode simulator

LICENSE=	GPLv2+

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs	\
		${LOCALBASE}/lib/libdxflib.a:cad/qcad	\
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libv8.so:lang/v8		\
		libre2.so:devel/re2		\
		libcbang0.so:devel/cbang	\
		liblz4.so:archivers/liblz4	\
		libevent.so:devel/libevent	\
		libexpat.so:textproc/expat2	\
		libyaml.so:textproc/libyaml	\
		libsnappy.so:archivers/snappy	\
		libsysinfo.so:devel/libsysinfo	\
		libleveldb.so:databases/leveldb

USE_GITHUB=	yes
GH_ACCOUNT=	CauldronDevelopmentLLC

USES=		compiler:c++14-lang desktop-file-utils gettext-runtime gl gnome	\
		localbase:ldflags mysql:client pkgconfig python qt:5 scons	\
		shared-mime-info shebangfix sqlite ssl
SHEBANG_FILES=	examples/python/camotics_python_example.py
USE_GL=		gl glu
USE_GNOME=	cairo
USE_QT=		assistant buildtools core dbus gui linguisttools network opengl	\
		websockets widgets
QT5_INC=	-I${LOCALBASE}/include/qt5	\
		-I${LOCALBASE}/include/qt5/QtCore	\
		-I${LOCALBASE}/include/qt5/QtGui	\
		-I${LOCALBASE}/include/qt5/QtNetwork	\
		-I${LOCALBASE}/include/qt5/QtOpenGL	\
		-I${LOCALBASE}/include/qt5/QtWidgets
QT5_LIBS_=	${qt-core_LIB}	\
		${qt-gui_LIB}	\
		${qt-network_LIB}	\
		${qt-opengl_LIB}	\
		${qt-websockets_LIB}	\
		${qt-widgets_LIB}
QT5_LIBS=	-L${QT_LIBDIR} ${QT5_LIBS_:C/^lib/-l/:C/.so//}

OPTIONS_DEFINE=		EXAMPLES
PORTEXAMPLES=	*

MAKE_ARGS+=	cc="${CC}"	\
		cxx="${CXX}"	\
		cxxstd="c++14"	\
		ccflags="${CCFLAGS}"	\
		cxxflags="${CXXFLAGS} ${QT5_INC}"	\
		linkflags="${LDFLAGS} ${QT5_LIBS}"	\
		libpath="${LIBPATH}"	\
		sharedlib=1	\
		install_prefix="${STAGEDIR}${PREFIX}"	\
		compiler="${CHOSEN_COMPILER_TYPE:C/gcc/gnu/}"	\
		disable_local="zlib bzip2 lz4 sqlite3 expat libevent re2 libyaml"
MAKE_ENV+=	QT5DIR="${LOCALBASE}"	\
		CBANG_HOME="${WRKDIR}/cbang"
.if defined(WITH_DEBUG)
MAKE_ARGS+=	debug=1 strict=0
.endif

TEST_WRKSRC=	${WRKSRC}/tests
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${TEST_ARGS}

pre-configure:
	${CP} -R ${LOCALBASE}/share/cbang ${WRKDIR}
	${RLN} ${LOCALBASE}/include ${WRKDIR}/cbang/
	${REINPLACE_CMD} -e "/python_version/s|'3'|'${PYTHON_VER}'|"	\
		${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e 's|/usr/bin/env python2| ${PYTHON_CMD}|'	\
		${TEST_WRKSRC}/testHarness

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo	\
		${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/CAMotics.desktop	\
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/CAMotics.appdata.xml	\
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/mime.xml	\
		${STAGEDIR}${PREFIX}/share/mime/packages/${PORTNAME}.xml
	${INSTALL_DATA} ${WRKSRC}/images/*.png	\
		${STAGEDIR}${PREFIX}/share/pixmaps

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

#do-test:
#	(cd ${TEST_WRKSRC} && ./testHarness)

.include <bsd.port.mk>
