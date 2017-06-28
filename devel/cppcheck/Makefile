# Created by: Gabor Pali <pgj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppcheck
PORTVERSION=	1.79
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Static analysis of C/C++ code

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: analyzerinfo.cpp: 'to_string' is not a member of 'std'

USES=		compiler:c++11-lib cmake shebangfix tar:bzip2
SHEBANG_FILES=	htmlreport/cppcheck-htmlreport

OPTIONS_DEFINE=		RULES GUI HTMLREPORT MANPAGES MATCHCOMPILER TEST
OPTIONS_DEFAULT=	RULES GUI HTMLREPORT MANPAGES MATCHCOMPILER
OPTIONS_SUB=		yes

RULES_DESC=		User-defined rule support (requires PCRE)
RULES_CMAKE_BOOL=	HAVE_RULES
RULES_LIB_DEPENDS=	libpcre.so:devel/pcre
RULES_USES=		localbase:ldflags

GUI_CMAKE_BOOL=		BUILD_GUI
GUI_USE=		QT4=corelib,gui,xml,qmake_build,moc_build,uic_build,rcc_build,linguisttools_build

TEST_CMAKE_BOOL=	BUILD_TESTS

HTMLREPORT_DESC=	Install cppcheck-htmlreport
HTMLREPORT_USES=	python:2,${PYUSE:C/ /,/W}
HTMLREPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments
HTMLREPORT_PLIST_FILES=	bin/cppcheck-htmlreport
HTMLREPORT_VARS=	PYUSE+=run

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

MATCHCOMPILER_DESC=	Build-time optimizations via Python
MATCHCOMPILER_CMAKE_BOOL=	USE_MATCHCOMPILER
MATCHCOMPILER_USES=	python:2,${PYUSE:C/ /,/W}
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

.include <bsd.port.mk>
