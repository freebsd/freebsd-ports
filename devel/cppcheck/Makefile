# Created by: Gabor Pali <pgj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppcheck
PORTVERSION=	2.0
PORTREVISION?=	0	# devel/cppcheck-gui
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT?=	Static analysis of C/C++ code

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib cmake:insource tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	danmar

.if defined(GUI_ONLY)
COMMENT=		Static analysis of C/C++ code (GUI)

RUN_DEPENDS=		cppcheck:devel/cppcheck

CMAKE_ARGS=		-DBUILD_GUI=TRUE
USES+=			qt:5
USE_QT=			core gui widgets printsupport qmake_build buildtools_build linguisttools_build

BUILD_WRKSRC=		${WRKSRC}/gui
INSTALL_WRKSRC=		${WRKSRC}/gui

PLIST=			${PKGDIR}/pkg-plist-gui

PKGNAMESUFFIX=		-gui
.else
USES+=			shebangfix
SHEBANG_FILES=		htmlreport/cppcheck-htmlreport

PORTDATA=		*

OPTIONS_DEFINE=		RULES HTMLREPORT MANPAGES MATCHCOMPILER TEST
OPTIONS_DEFAULT=	RULES HTMLREPORT MANPAGES MATCHCOMPILER
OPTIONS_SUB=		yes

RULES_DESC=		User-defined rule support (requires PCRE)
RULES_CMAKE_BOOL=	HAVE_RULES
RULES_LIB_DEPENDS=	libpcre.so:devel/pcre
RULES_USES=		localbase:ldflags

TEST_CMAKE_BOOL=	BUILD_TESTS

HTMLREPORT_DESC=	Install cppcheck-htmlreport
HTMLREPORT_USES=	python:${PYUSE:C/ /,/W}
HTMLREPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
HTMLREPORT_PLIST_FILES=	bin/cppcheck-htmlreport
HTMLREPORT_VARS=	PYUSE+=run

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

MATCHCOMPILER_DESC=	Build-time optimizations via Python
MATCHCOMPILER_CMAKE_BOOL=	USE_MATCHCOMPILER
MATCHCOMPILER_USES=	python:${PYUSE:C/ /,/W}
MATCHCOMPILER_VARS=	PYUSE+=build

post-patch:
	@${REINPLACE_CMD} -e '/find_package(Qt5/ d' ${WRKSRC}/cmake/findDependencies.cmake

post-install-HTMLREPORT-on:
	${INSTALL_SCRIPT} ${WRKSRC}/htmlreport/cppcheck-htmlreport ${STAGEDIR}${PREFIX}/bin

post-build-MANPAGES-on:
	cd ${WRKSRC}/man && ${LOCALBASE}/bin/xsltproc --nonet --param man.charmap.use.subset "0" \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl cppcheck.1.xml

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/cppcheck.1 ${STAGEDIR}${PREFIX}/man/man1

do-test-TEST-on:
	cd ${WRKSRC} && ctest
.endif

.include <bsd.port.mk>
