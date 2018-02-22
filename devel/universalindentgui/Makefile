# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	universalindentgui
PORTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF/universalindent/uigui/UniversalIndentGUI_${PORTVERSION}

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Graphical UI for multiple source code indent/format/beautify tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2

USES=		dos2unix qmake python:run shebangfix
SHEBANG_FILES=	indenters/*.py indenters/*.rb
USE_QT4=	corelib moc_build uic_build rcc_build \
		linguist_build network script gui

DESKTOP_ENTRIES="UniversalIndentGUI" "${COMMENT}" "" "${PORTNAME}" "" true

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/#${PREFIX}/#g' -e 's#/share/man/#/man/#g' \
		${WRKSRC}/UniversalIndentGUI.pro ${WRKSRC}/src/SettingsPaths.cpp
	@${REINPLACE_CMD} -e 's#debug_and_release#release#g' \
		${WRKSRC}/UniversalIndentGUI.pro

.include <bsd.port.mk>
