PORTNAME=	cpeditor
DISTVERSION=	7.1.1-45
DISTVERSIONSUFFIX=	-ge836127
CATEGORIES=	editors devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and cross-platform code editor for competitive programming
WWW=		https://cpeditor.org/ \
		https://github.com/cpeditor/cpeditor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja compiler:c++14-lang desktop-file-utils gl kde:6 qt:6
USE_QT=		5compat base tools:build
USE_GL=		gl opengl
USE_KDE=	syntaxhighlighting

USE_GITHUB=	yes
GH_TUPLE=	cpeditor:FakeVim:50b62ce:FakeVim/third_party/FakeVim \
		itay-grudev:SingleApplication:a218603:itay_grudev_SingleApplication/third_party/singleapplication \
		cpeditor:QtFindReplaceDialog:d190d9b:cpeditor_QtFindReplaceDialog/third_party/QtFindReplaceDialog \
		cpeditor:lsp-cpp:6dcfd56:cpeditor_lsp_cpp/third_party/lsp-cpp \
		cpeditor:qhttp:091cebd:cpeditor_qhttp/third_party/qhttp \
		MikeMirzayanov:testlib:1e4e8a2:MikeMirzayanov_testlib/third_party/testlib

PLIST_FILES=	bin/cpeditor \
		share/applications/cpeditor.desktop \
		share/icons/hicolor/512x512/apps/cpeditor.png \
		share/metainfo/cpeditor.appdata.xml

.include <bsd.port.mk>
