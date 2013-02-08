# New ports collection makefile for:	universalindentgui
# Date created:		2009-09-30
# Whom:			Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	universalindentgui
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/universalindent/uigui/UniversalIndentGUI_${PORTVERSION}

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Graphical UI for multiple source code indent/format/beautify tools

LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2

USE_QT4=	qmake_build moc_build uic_build rcc_build \
		linguist network script gui
HAS_CONFIGURE=	yes

MAN1=		universalindentgui.1
MANCOMPRESSED=	yes

QMAKE_ARGS=	-unix PREFIX=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/#${PREFIX}/#g' -e 's#/share/man/#/man/#g' \
		${WRKSRC}/UniversalIndentGUI.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
