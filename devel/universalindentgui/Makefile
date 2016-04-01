# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	universalindentgui
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/universalindent/uigui/UniversalIndentGUI_${PORTVERSION}

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Graphical UI for multiple source code indent/format/beautify tools

LIB_DEPENDS=	libqscintilla2.so:devel/qscintilla2

USES=		dos2unix qmake shebangfix
SHEBANG_FILES=	indenters/pindent.py \
		indenters/rbeautify.rb \
		indenters/ruby_formatter.rb
USE_QT4=	moc_build uic_build rcc_build \
		linguist_build network script gui

DESKTOP_ENTRIES="UniversalIndentGUI" "${COMMENT}" "" "${PORTNAME}" "" true

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/#${PREFIX}/#g' -e 's#/share/man/#/man/#g' \
		${WRKSRC}/UniversalIndentGUI.pro ${WRKSRC}/src/SettingsPaths.cpp
	@${REINPLACE_CMD} -e 's#debug_and_release#release#g' \
		${WRKSRC}/UniversalIndentGUI.pro

.include <bsd.port.mk>
