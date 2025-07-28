PORTNAME=	cppcheck
DISTVERSION=	2.18.0
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool for static C/C++ code analysis
WWW=		https://cppcheck.sourceforge.io/ \
		https://github.com/danmar/cppcheck

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtinyxml2.so:textproc/tinyxml2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/container/small_vector.hpp:devel/boost-libs

USES=		compiler:c++11-lib shebangfix tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	danmar
SHEBANG_FILES=	htmlreport/cppcheck-htmlreport
CMAKE_OFF=	USE_BUNDLED_TINYXML2
CMAKE_ON=	USE_BOOST USE_QT6

PORTDATA=		*

OPTIONS_DEFINE=		RULES HTMLREPORT MANPAGES MATCHCOMPILER GUI CHARTS TEST
OPTIONS_DEFAULT=	RULES HTMLREPORT MANPAGES MATCHCOMPILER GUI
OPTIONS_SUB=		yes

RULES_DESC=		User-defined rule support (requires PCRE)
RULES_CMAKE_BOOL=	HAVE_RULES
RULES_LIB_DEPENDS=	libpcre.so:devel/pcre
RULES_USES=		localbase:ldflags

TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_IMPLIES=		GUI
TEST_USES=		cmake:testing
TEST_USES_OFF=		cmake

HTMLREPORT_DESC=	Install cppcheck-htmlreport
HTMLREPORT_USES=	python:${PYUSE:C/ /,/W}
HTMLREPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
HTMLREPORT_VARS=	PYUSE+=run

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

MATCHCOMPILER_DESC=	Build-time optimizations via Python
MATCHCOMPILER_CMAKE_ON=	-DUSE_MATCHCOMPILER=On
MATCHCOMPILER_CMAKE_OFF=-DUSE_MATCHCOMPILER=Off
MATCHCOMPILER_USES=	python:${PYUSE:C/ /,/W}
MATCHCOMPILER_VARS=	PYUSE+=build

GUI_DESC=		Build the Qt GUI application
GUI_CMAKE_BOOL=		BUILD_GUI
GUI_USES=		qt:6
GUI_USE=		QT=base,tools:build

CHARTS_DESC=		Enable QtCharts usage in the GUI
CHARTS_CMAKE_BOOL=	WITH_QCHART
CHARTS_IMPLIES=		GUI
CHARTS_USE=		QT=charts

post-patch:
	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|' ${WRKSRC}/test/testfilelister.cpp

post-install-HTMLREPORT-on:
	${INSTALL_SCRIPT} ${WRKSRC}/htmlreport/cppcheck-htmlreport ${STAGEDIR}${PREFIX}/bin

post-build-MANPAGES-on:
	cd ${WRKSRC}/man && ${LOCALBASE}/bin/xsltproc --nonet --param man.charmap.use.subset "0" \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl cppcheck.1.xml

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/cppcheck.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-test-TEST-on:
	cd ${BUILD_WRKSRC} && ${SETENV} ${TEST_ENV} ctest

.include <bsd.port.mk>
