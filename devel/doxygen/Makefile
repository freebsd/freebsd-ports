PORTNAME=	doxygen
PORTVERSION=	1.9.6
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/rel-${PORTVERSION} \
		http://doxygen.nl/files/
EXTRACT_SUFX=	.src.tar.gz

PATCH_SITES=	https://github.com/doxygen/doxygen/commit/
PATCHFILES=	966d69c603b5a6ae22e3132b6ecc6a39b86e52ab.patch:-p1 \
		7b2a6027775b0158304635a98de0f9b5672f163a.patch:-p1 \
		f3514d578633cad3e39d6787f81085e46bafbaf4.patch:-p1 \
		8129939c312e4b5060042fdb93bd071b7b133381.patch:-p1

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Documentation system for C, C++, and other languages
WWW=		https://www.doxygen.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison cmake compiler:c++17-lang cpe dos2unix \
		iconv python shebangfix

ALL_TARGET=	all
CMAKE_ARGS+=	-DDOC_INSTALL_DIR:PATH=${DOCSDIR_REL}
CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0116=OLD  # temporary workaround for old Doxygen
CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0148=OLD  # temporary workaround for old Doxygen

EXTRACT_AFTER_ARGS=	--exclude '*/libmd5'

DOS2UNIX_FILES=	doc/translator.py
PLIST_FILES=	bin/doxygen

OPTIONS_DEFINE=	DOCS GRAPHVIZ LATEX SEARCH QT5
OPTIONS_DEFAULT=	GRAPHVIZ
QT5_DESC=	Install Doxywizard GUI with Qt5
SEARCH_DESC=	Build external search tools (doxysearch and doxyindexer)

DOCS_USES=		ghostscript:build tex
DOCS_USE=		TEX=base:build,dvipsk:build,pdftex:build
DOCS_ALL_TARGET=	docs
DOCS_BUILD_DEPENDS=	dot:graphics/graphviz
DOCS_CMAKE_BOOL=	build_doc
DOCS_PLIST_FILES=	share/man/man1/doxygen.1.gz \
			share/man/man1/doxyindexer.1.gz \
			share/man/man1/doxysearch.1.gz \
			share/man/man1/doxywizard.1.gz

PORTDOCS=		*

GRAPHVIZ_RUN_DEPENDS=	dot:graphics/graphviz

LATEX_USES=	tex
LATEX_USE=	TEX=base,dvipsk,pdftex

QT5_USES=	qt:5
QT5_USE=	QT=core,widgets,gui,xml,qmake:build,buildtools:build
QT5_CMAKE_BOOL=	build_wizard
QT5_PLIST_FILES=	bin/doxywizard

SEARCH_CMAKE_BOOL=	build_search
SEARCH_LIB_DEPENDS=	libxapian.so:databases/xapian-core
SEARCH_PLIST_FILES=	bin/doxyindexer \
			bin/doxysearch.cgi

post-extract:	# clean up garbage in tarball
		${RM} ${WRKSRC}/templates/html/._resize.js
		${RM} ${WRKSRC}/src/._htmlgen.h
		${RM} ${WRKSRC}/src/._formula.h


.include <bsd.port.mk>
