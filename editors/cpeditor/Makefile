PORTNAME=	cpeditor
DISTVERSION=	6.8.2
CATEGORIES=	editors devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and cross-platform code editor for competitive programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja compiler:c++14-lang qt:5
USE_QT=		core gui network widgets \
		buildtools_build linguisttools_build qmake_build
USE_GITHUB=	yes
GH_TUPLE=	\
		cpeditor:QCodeEditor:ca5f949:cpeditor_QCodeEditor/third_party/QCodeEditor \
		itay-grudev:SingleApplication:c557da5:itay_grudev_SingleApplication/third_party/singleapplication \
		cpeditor:QtFindReplaceDialog:6c3391c:cpeditor_QtFindReplaceDialog/third_party/QtFindReplaceDialog \
		cpeditor:lsp-cpp:1825fd7:cpeditor_lsp_cpp/third_party/lsp-cpp \
		cpeditor:qhttp:fd780d2:cpeditor_qhttp/third_party/qhttp \
		MikeMirzayanov:testlib:f5b55f1:MikeMirzayanov_testlib/third_party/testlib

PLIST_FILES=	bin/cpeditor \
		share/applications/cpeditor.desktop \
		share/icons/hicolor/512x512/apps/cpeditor.png

.include <bsd.port.mk>
