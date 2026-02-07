PORTNAME=	texstudio
DISTVERSION=	4.9.0
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Integrated writing environment for LaTeX documents
WWW=		https://texstudio.sourceforge.net/

LICENSE=	GPLv2

BROKEN_armv6=	fails to compile: error: no member named mc_eip in __mcontext

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libquazip1-qt6.so:archivers/quazip@qt6

USES=		cmake compiler:c++20-lang desktop-file-utils dos2unix \
		ghostscript:run gl pkgconfig qt:6 tex xorg

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-org

USE_QT	=	5compat base tools

USE_XORG=	x11
USE_GL=		gl
USE_TEX=	latex dvipsk

DOS2UNIX_FILES=	${PORTNAME}.pro \
		src/manhattanstyle.cpp \
		src/pdfviewer/PDFDocument.h \
		src/qcodeedit/lib/widgets/qfoldpanel.cpp

.include <bsd.port.mk>
