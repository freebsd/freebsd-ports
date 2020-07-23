# $FreeBSD$

PORTNAME=	cpeditor
DISTVERSION=	6.6.2
CATEGORIES=	editors devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and cross-platform code editor for competitive programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang qt:5
USE_QT=		core gui network widgets buildtools_build linguisttools_build qmake_build
USE_GITHUB=	yes
GH_TUPLE=	\
		cpeditor:QCodeEditor:baf096a7f2d4898913640f9f0bc401659fe2c087:cpeditor_QCodeEditor/third_party/QCodeEditor \
		itay-grudev:SingleApplication:e93c12ab69a25fcaa963416f0e348d3269263190:itay_grudev_SingleApplication/third_party/singleapplication \
		cpeditor:QtFindReplaceDialog:d6adb0091641aed078e1f41a48278374fa3b328b:cpeditor_QtFindReplaceDialog/third_party/QtFindReplaceDialog \
		cpeditor:lsp-cpp:44e7cdea787c19646f3c88ba8cbd0ed5da02b9cd:cpeditor_lsp_cpp/third_party/lsp-cpp \
		MikeMirzayanov:testlib:7354daf4a2a90868ef267185c23f14c30799c4a6:MikeMirzayanov_testlib/third_party/testlib

PLIST_FILES=	bin/cpeditor \
		share/applications/cpeditor.desktop \
		share/icons/cpeditor-icon.png

.include <bsd.port.mk>
