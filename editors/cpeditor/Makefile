PORTNAME=	cpeditor
DISTVERSION=	7.0.1
CATEGORIES=	editors devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and cross-platform code editor for competitive programming
WWW=		https://cpeditor.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja compiler:c++17-lang desktop-file-utils kde:5 qt:5
USE_QT=		core gui network widgets \
		buildtools:build linguisttools:build qmake:build
USE_KDE=	syntaxhighlighting

USE_GITHUB=	yes
GH_TUPLE=	itay-grudev:SingleApplication:494772e:itay_grudev_SingleApplication/third_party/singleapplication \
		cpeditor:QtFindReplaceDialog:a86ed0b:cpeditor_QtFindReplaceDialog/third_party/QtFindReplaceDialog \
		cpeditor:lsp-cpp:69c8afa:cpeditor_lsp_cpp/third_party/lsp-cpp \
		cpeditor:qhttp:fd780d2a0bee1246f2ab0a17f6eebab6403fce64:cpeditor_qhttp/third_party/qhttp \
		MikeMirzayanov:testlib:d0a0161:MikeMirzayanov_testlib/third_party/testlib

PLIST_FILES=	bin/cpeditor \
		share/applications/cpeditor.desktop \
		${DATADIR}/translations/el_GR.qm \
		${DATADIR}/translations/es_MX.qm \
		${DATADIR}/translations/pt_BR.qm \
		${DATADIR}/translations/ru_RU.qm \
		${DATADIR}/translations/zh_CN.qm \
		${DATADIR}/translations/zh_TW.qm \
		share/icons/hicolor/512x512/apps/cpeditor.png \
		share/metainfo/cpeditor.appdata.xml

.include <bsd.port.mk>
