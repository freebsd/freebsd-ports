# Created by: Gabor Pali <pgj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppcheck
PORTVERSION=	1.81
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT?=	Static analysis of C/C++ code

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=			compiler:c++11-lib cmake tar:bzip2

.if defined(GUI_ONLY)
COMMENT=		Static analysis of C/C++ code (GUI)

RUN_DEPENDS=		cppcheck:devel/cppcheck

CMAKE_ARGS=		-DBUILD_GUI=TRUE
USE_QT5=		core gui widgets printsupport qmake_build buildtools_build linguisttools_build

BUILD_WRKSRC=		${WRKSRC}/gui
INSTALL_WRKSRC=		${WRKSRC}/gui

PLIST=			${PKGDIR}/pkg-plist-gui

PKGNAMESUFFIX=		-gui
.else
USES+=			shebangfix
SHEBANG_FILES=		htmlreport/cppcheck-htmlreport

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
