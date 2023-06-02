PORTNAME=	notepadnext
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
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

GH_TUPLE=	alex-spataru:QSimpleUpdater:62e0ce7dde4c76e7533f2f0ee53f19ee1690c8dd:alex_spataru_QSimpleUpdater/src/QSimpleUpdater \
		editorconfig:editorconfig-core-qt:52820d59769fcba6d0ed94f685406c0383fe1a30:editorconfig_editorconfig_core_qt/src/editorconfig-core-qt \
		githubuser0xFFFF:Qt-Advanced-Docking-System:89ff0ad:githubuser0xFFFF_Qt_Advanced_Docking_System/src/ads \
		itay-grudev:SingleApplication:d0c43a5:itay_grudev_SingleApplication/src/singleapplication

QMAKE_SOURCE_PATH=	${WRKSRC}/src/NotepadNext.pro

CXXFLAGS+=	-I${LOCALBASE}/include/uchardet
LDFLAGS+=	-luchardet

PLIST_FILES=	bin/NotepadNext \
		share/applications/NotepadNext.desktop \
		share/icons/hicolor/scalable/apps/NotepadNext.svg \
		share/icons/hicolor/scalable/mimetypes/NotepadNext.svg

.include <bsd.port.mk>
