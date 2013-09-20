# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	universalindentgui
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	SF/universalindent/uigui/UniversalIndentGUI_${PORTVERSION}

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Graphical UI for multiple source code indent/format/beautify tools

LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2

USE_DOS2UNIX=	yes
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		linguist network script gui
HAS_CONFIGURE=	yes

MAN1=		universalindentgui.1
MANCOMPRESSED=	yes

QMAKE_ARGS=	-unix PREFIX=${PREFIX}

DESKTOP_ENTRIES="UniversalIndentGUI" "${COMMENT}" "" "${PORTNAME}" "" true

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's#/usr/#${PREFIX}/#g' -e 's#/share/man/#/man/#g' \
		${WRKSRC}/UniversalIndentGUI.pro ${WRKSRC}/src/SettingsPaths.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS}

post-configure:
	@${REINPLACE_CMD} 's|-pipe -O2|${CFLAGS}|' ${WRKSRC}/Makefile.Release
	@${REINPLACE_CMD} 's|-pipe -g|${CFLAGS}|' ${WRKSRC}/Makefile.Debug

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
