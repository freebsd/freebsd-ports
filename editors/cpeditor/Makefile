# $FreeBSD$

PORTNAME=	cpeditor
DISTVERSION=	6.8.1
CATEGORIES=	editors devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and cross-platform code editor for competitive programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang qt:5
USE_QT=		core gui network widgets buildtools_build linguisttools_build qmake_build
USE_GITHUB=	yes
GH_TUPLE=	\
		cpeditor:QCodeEditor:32719697664220911921b4c9f3bb09cdb43166ce:cpeditor_QCodeEditor/third_party/QCodeEditor \
		itay-grudev:SingleApplication:4aeac8fa3e7e96385ba556346ebb6020e35ffdd8:itay_grudev_SingleApplication/third_party/singleapplication \
		cpeditor:QtFindReplaceDialog:d6adb0091641aed078e1f41a48278374fa3b328b:cpeditor_QtFindReplaceDialog/third_party/QtFindReplaceDialog \
		cpeditor:lsp-cpp:44e7cdea787c19646f3c88ba8cbd0ed5da02b9cd:cpeditor_lsp_cpp/third_party/lsp-cpp \
		cpeditor:qhttp:fd780d2a0bee1246f2ab0a17f6eebab6403fce64:cpeditor_qhttp/third_party/qhttp \
		MikeMirzayanov:testlib:f5b55f138709e97916f51bdb7a23baed941b5751:MikeMirzayanov_testlib/third_party/testlib

PLIST_FILES=	bin/cpeditor \
		share/applications/cpeditor.desktop \
		share/icons/hicolor/512x512/apps/cpeditor.png

.include <bsd.port.mk>
