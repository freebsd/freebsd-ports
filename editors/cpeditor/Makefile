# $FreeBSD$

PORTNAME=	cpeditor
DISTVERSION=	6.6.5
CATEGORIES=	editors devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and cross-platform code editor for competitive programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang qt:5
USE_QT=		core gui network widgets buildtools_build linguisttools_build qmake_build
USE_GITHUB=	yes
GH_TUPLE=	\
		cpeditor:QCodeEditor:97cdee8a47a0c6d61a1587d23e6f26b870333936:cpeditor_QCodeEditor/third_party/QCodeEditor \
		itay-grudev:SingleApplication:e93c12ab69a25fcaa963416f0e348d3269263190:itay_grudev_SingleApplication/third_party/singleapplication \
		cpeditor:QtFindReplaceDialog:d6adb0091641aed078e1f41a48278374fa3b328b:cpeditor_QtFindReplaceDialog/third_party/QtFindReplaceDialog \
		cpeditor:lsp-cpp:44e7cdea787c19646f3c88ba8cbd0ed5da02b9cd:cpeditor_lsp_cpp/third_party/lsp-cpp \
		MikeMirzayanov:testlib:1277b269ec417dc01a786a6775a10b9189a0fadc:MikeMirzayanov_testlib/third_party/testlib \

PLIST_FILES=	bin/cpeditor \
		share/applications/cpeditor.desktop \
		share/icons/cpeditor-icon.png

.include <bsd.port.mk>
