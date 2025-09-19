PORTNAME=	klayout
PORTVERSION=	0.28.17
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Qt-based chip mask layout viewing and editing tool
WWW=		http://www.klayout.de/index.html

LICENSE=	GPLv2

BROKEN_i386=	type 'hash<long long>' does not provide a call operator
BROKEN_powerpc=	type 'hash<long long>' does not provide a call operator

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++0x gmake gl python ruby qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	KLayout
USE_GL=		gl
USE_QT=		core buildtools designer gui multimedia network printsupport \
		qmake sql svg testlib uitools widgets xml xmlpatterns
USE_LDCONFIG=	yes

CXXFLAGS+=	-fdeclspec -fPIC -I${LOCALBASE}/include/qt5 \
		${QT5MODULES:S,^,-I${LOCALBASE}/include/qt5/Qt,}
LDFLAGS+=	${LIBS} ${QT5MODULES:S,^,-lQt5,} \
		-L${LOCALBASE}/lib/qt5 -lpthread
QT5MODULES=	Core Designer Gui Multimedia MultimediaWidgets \
		Network PrintSupport Sql Svg Test Widgets Xml XmlPatterns
MAKE_ENV=	INSTALLROOT=${STAGEDIR} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
BUILD_WRKSRC=	${WRKSRC}/build-release
INSTALL_WRKSRC=	${WRKSRC}/build-release
TEST_WRKSRC=	${WRKSRC}/build-release
PLIST_SUB=	PORTVERSION=${PORTVERSION} PORTVERSION_R=${PORTVERSION:R}

CONFIGURE_SHELL=	${LOCALBASE}/bin/bash

do-configure:
	cd ${WRKSRC} && \
	    ${SETENV} ${MAKE_ENV} ${CONFIGURE_SHELL} build.sh \
		-with-qtbinding \
		-rpath "${PREFIX}/lib/klayout" \
		-prefix "${PREFIX}" \
		-python ${PYTHON_CMD} \
		-ruby ${RUBY} \
		-nolibgit2 \
		-dry-run

post-configure:
	${ECHO_CMD} "#define PLUGINS_BASEDIR \"${PREFIX}/lib/klayout\"" \
	    > ${WRKSRC}/src/lay/lay/laySystemPathsDefaults.h

pre-install:
	for D in lib db tl rdb pya; do \
	    ${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/klayout/$${D}; \
	done
	for D in db_plugins lay_plugins; do \
	    ${MKDIR} ${STAGEDIR}${PREFIX}/lib/klayout/$${D}; \
	done

post-install:
	cd ${INSTALL_WRKSRC} && \
	    ${STRIP_CMD} `${FIND} libklayout*so* -type f` && \
	    ${MV} libklayout*so* ${STAGEDIR}${PREFIX}/lib/klayout
.for D in db_plugins lay_plugins
	cd ${INSTALL_WRKSRC}/$D && \
	    ${STRIP_CMD} `${FIND} *so* -type f` && \
	    ${MV} *so* ${STAGEDIR}${PREFIX}/lib/klayout/$D
.endfor
	cd ${INSTALL_WRKSRC}/pymod && \
	    ${STRIP_CMD} `${FIND} lib*so* -type f` && \
	    ${MV} lib*so* ${STAGEDIR}${PREFIX}/lib/klayout
	cd ${STAGEDIR}${PYTHON_SITELIBDIR}/klayout && \
	    ${STRIP_CMD} `${FIND} *.so -type f`
	cd ${INSTALL_WRKSRC} && \
	    ${INSTALL_PROGRAM} klayout strm* ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${TEST_WRKSRC} && \
	    ${SETENV} QT_QPA_PLATFORM=offscreen TESTTMP=testtmp TESTSRC=.. \
	    LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib/klayout/db_plugins:${STAGEDIR}${PREFIX}/lib/klayout/lay_plugins \
	    ./ut_runner

.include <bsd.port.mk>
