PORTNAME=	notepadnext
PORTVERSION=	${NPNEXT_COMMIT_DATE}
CATEGORIES=	editors
PKGNAMESUFFIX=	-devel

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Reimplementation of Notepad++
WWW=		https://github.com/dail8859/NotepadNext

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	notepadnext-[0-9]*

LIB_DEPENDS=	libuchardet.so:textproc/uchardet

USES=		desktop-file-utils gl qmake qt:5 xorg
USE_QT=		core gui network printsupport widgets buildtools:build linguisttools:build
USE_GL=		gl
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	dail8859
GH_PROJECT=	NotepadNext
GH_TAGNAME=	5bf18d9
NPNEXT_COMMIT_DATE=	2025.02.17

GH_TUPLE=	alex-spataru:QSimpleUpdater:3cc832c:alex_spataru_QSimpleUpdater/src/QSimpleUpdater \
		editorconfig:editorconfig-core-qt:ee967262db4fdbd735f9971cc0c90cf4f3100d3a:editorconfig_editorconfig_core_qt/src/editorconfig-core-qt \
			editorconfig:editorconfig-core-test:7d75ceb:editorconfig_editorconfig_core_test/src/editorconfig-core-qt/tests \
		githubuser0xFFFF:Qt-Advanced-Docking-System:644c828f007fba8dda4292dde432f29f69793362:githubuser0xFFFF_Qt_Advanced_Docking_System/src/ads \
		itay-grudev:SingleApplication:0ba7b6c:itay_grudev_SingleApplication/src/singleapplication

QMAKE_SOURCE_PATH=	${WRKSRC}/src/NotepadNext.pro

CXXFLAGS+=	-I${LOCALBASE}/include/uchardet
LDFLAGS+=	-luchardet

PLIST_FILES=	bin/NotepadNext \
		share/applications/NotepadNext.desktop \
		share/icons/hicolor/scalable/apps/NotepadNext.svg \
		share/icons/hicolor/scalable/mimetypes/NotepadNext.svg

.include <bsd.port.mk>
