# Created by: Joep Grooten <joep@di.nl>
# $FreeBSD$

PORTNAME=	doxygen
PORTVERSION=	1.8.10
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Documentation system for C, C++, and other languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison cmake:outsource iconv python:2
ALL_TARGET=	all
CMAKE_ARGS+=	-DDOC_INSTALL_DIR:PATH=${DOCSDIR_REL}
REINPLACE_ARGS=	-i ''

EXTRACT_AFTER_ARGS=	--exclude '*/libmd5' \
			--exclude '*/libpng' \
			--exclude '*/tmake'

PLIST_FILES=	bin/doxygen

OPTIONS_DEFINE=	GRAPHVIZ LATEX QT4 DOCS
OPTIONS_DEFAULT=	GRAPHVIZ LATEX
QT4_DESC=	Install Doxywizard GUI

GRAPHVIZ_RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

LATEX_USE=	TEX=base,dvipsk,pdftex

QT4_USE=	QT4=corelib,gui,xml,qmake_build,moc_build,rcc_build,uic_build
QT4_CMAKE_ON=		-Dbuild_wizard:BOOLEAN=ON
QT4_CMAKE_OFF=		-Dbuild_wizard:BOOLEAN=OFF
QT4_PLIST_FILES=	bin/doxywizard

DOCS_USES=		ghostscript:build
DOCS_ALL_TARGET=	docs
DOCS_BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
DOCS_CMAKE_ON=		-Dbuild_doc:BOOLEAN=ON
DOCS_CMAKE_OFF=		-Dbuild_doc:BOOLEAN=OFF
DOCS_PLIST_FILES=	man/man1/doxygen.1.gz \
			man/man1/doxyindexer.1.gz \
			man/man1/doxysearch.1.gz \
			man/man1/doxywizard.1.gz
PORTDOCS=		*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && empty(PORT_OPTIONS:MLATEX)
IGNORE=		cannot build Doxygen's PDF docs without option LATEX enabled
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE=${LOCALBASE}/bin/flex
.endif

.include <bsd.port.mk>
