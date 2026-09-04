PORTNAME=	doxygen
DISTVERSIONPREFIX=	Release_
DISTVERSION=	1.18.0
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/Release_${DISTVERSION:C/\./_/g}/ \
		https://doxygen.nl/files/
DISTNAME=	${PORTNAME}-${DISTVERSION}.src

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Documentation system for C, C++, and other languages
WWW=		https://www.doxygen.nl/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog
TEST_DEPENDS=	${LOCALBASE}/bin/xmllint:textproc/libxml2

USES=		bison cmake compiler:c++20-lang cpe iconv \
		localbase:ldflags python:build sqlite

EXTRACT_CMD=	${SETENV} LC_ALL=C.UTF-8 ${TAR}
EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-${DISTVERSION}/deps/fmt \
			--exclude ${PORTNAME}-${DISTVERSION}/deps/spdlog \
			--exclude ${PORTNAME}-${DISTVERSION}/deps/sqlite3 \
			--no-same-owner --no-same-permissions

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

LDFLAGS+=	-Wl,--as-needed

PORTDOCS=	*
PLIST_FILES=	bin/doxygen \
		share/man/man1/doxygen.1.gz

TEST_TARGET=	test

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_generateDS \
		use_sys_fmt \
		use_sys_spdlog \
		use_sys_sqlite3
CMAKE_ARGS=	-DDOC_INSTALL_DIR:PATH=${DOCSDIR_REL} \
		-DGIT_EXECUTABLE:STRING=false \
		-DCMAKE_CTEST_ARGUMENTS="-E;012_cite"

OPTIONS_DEFINE=	DOCS GRAPHVIZ LATEX QT6 SEARCH
OPTIONS_DEFAULT=GRAPHVIZ

QT6_DESC=	Install Doxywizard GUI with QT6
SEARCH_DESC=	Build external search tools (doxysearch and doxyindexer)

DOCS_USES=		ghostscript:build tex
DOCS_USE=		TEX=base:build,dvipsk:build,pdftex:build
DOCS_ALL_TARGET=	docs
DOCS_BUILD_DEPENDS=	dot:graphics/graphviz
DOCS_CMAKE_BOOL=	build_doc

GRAPHVIZ_RUN_DEPENDS=	dot:graphics/graphviz

LATEX_USES=		tex
LATEX_USE=		TEX=base,dvipsk,pdftex

QT6_USES=		qt:6
QT6_USE=		QT=base,svg
QT6_CMAKE_BOOL=		build_wizard
QT6_CMAKE_ON=		-Dforce_qt=Qt6
QT6_PLIST_FILES=	bin/doxywizard \
			share/man/man1/doxywizard.1.gz

SEARCH_LIB_DEPENDS=	libxapian.so:databases/xapian-core
SEARCH_CMAKE_BOOL=	build_search
SEARCH_PLIST_FILES=	bin/doxyindexer \
			bin/doxysearch.cgi \
			share/man/man1/doxyindexer.1.gz \
			share/man/man1/doxysearch.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION:C/\./_/g}|g' \
	     ${PATCH_WRKSRC}/cmake/git_watcher.cmake
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION:C/\./_/g}|g' \
	    ${PATCH_WRKSRC}/libversion/gitversion.cpp.in

.include <bsd.port.mk>
