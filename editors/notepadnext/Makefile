PORTNAME=	notepadnext
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reimplementation of Notepad++
WWW=		https://github.com/dail8859/NotepadNext

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuchardet.so:textproc/uchardet

USES=		desktop-file-utils gl qmake qt:5 xorg
USE_QT=		core gui network printsupport widgets buildtools:build linguisttools:build
USE_GL=		gl
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	dail8859
GH_PROJECT=	NotepadNext

GH_TUPLE=	alex-spataru:QSimpleUpdater:e4d8c73:alex_spataru_QSimpleUpdater/src/QSimpleUpdater \
		editorconfig:editorconfig-core-qt:52820d59769fcba6d0ed94f685406c0383fe1a30:editorconfig_editorconfig_core_qt/src/editorconfig-core-qt \
			editorconfig:editorconfig-core-test:70840cfaf6a06766ab61e975b8a1fe3b891ee08e:editorconfig_editorconfig_core_test/src/editorconfig-core-qt/tests \
		githubuser0xFFFF:Qt-Advanced-Docking-System:ec018a4:githubuser0xFFFF_Qt_Advanced_Docking_System/src/ads \
		itay-grudev:SingleApplication:8c48163:itay_grudev_SingleApplication/src/singleapplication

QMAKE_SOURCE_PATH=	${WRKSRC}/src/NotepadNext.pro

CXXFLAGS+=	-I${LOCALBASE}/include/uchardet
LDFLAGS+=	-luchardet

PLIST_FILES=	bin/NotepadNext \
		share/applications/NotepadNext.desktop \
		share/icons/hicolor/scalable/apps/NotepadNext.svg \
		share/icons/hicolor/scalable/mimetypes/NotepadNext.svg

.include <bsd.port.mk>
