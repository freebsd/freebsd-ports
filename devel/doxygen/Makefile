# Created by: Joep Grooten <joep@di.nl>
# $FreeBSD$

PORTNAME=	doxygen
PORTVERSION=	1.8.15
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	http://doxygen.nl/files/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Documentation system for C, C++, and other languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison cmake:noninja compiler:c++11-lang iconv python shebangfix

ALL_TARGET=	all
CMAKE_ARGS+=	-DDOC_INSTALL_DIR:PATH=${DOCSDIR_REL}
# Parallel jobs breaks when the DOCS option is on
MAKE_JOBS_UNSAFE=	yes

EXTRACT_AFTER_ARGS=	--exclude '*/libmd5'

PLIST_FILES=	bin/doxygen

OPTIONS_DEFINE=	DOCS GRAPHVIZ LATEX SEARCH QT5
OPTIONS_DEFAULT=	GRAPHVIZ LATEX
QT5_DESC=	Install Doxywizard GUI with Qt5
SEARCH_DESC=	Build external search tools (doxysearch and doxyindexer)

DOCS_USES=		ghostscript:build
DOCS_ALL_TARGET=	docs
DOCS_BUILD_DEPENDS=	dot:graphics/graphviz
DOCS_CMAKE_BOOL=	build_doc
DOCS_PLIST_FILES=	man/man1/doxygen.1.gz \
			man/man1/doxyindexer.1.gz \
			man/man1/doxysearch.1.gz \
			man/man1/doxywizard.1.gz
DOCS_IMPLIES=		LATEX
PORTDOCS=		*

GRAPHVIZ_RUN_DEPENDS=	dot:graphics/graphviz

LATEX_USE=	TEX=base,dvipsk,pdftex

QT5_USES=	qt:5
QT5_USE=	QT=core,widgets,gui,xml,qmake_build,buildtools_build
QT5_CMAKE_ON=	-Dbuild_wizard:BOOLEAN=true
QT5_PLIST_FILES=	bin/doxywizard

SEARCH_CMAKE_BOOL=	build_search
SEARCH_LIB_DEPENDS=	libxapian.so:databases/xapian-core
SEARCH_PLIST_FILES=	bin/doxyindexer \
			bin/doxysearch.cgi

post-patch:
	@${REINPLACE_CMD} -e '/PERL_PATH/ s|/usr/bin/perl|${perl_CMD}|' \
		${WRKSRC}/src/config.xml

.include <bsd.port.mk>
