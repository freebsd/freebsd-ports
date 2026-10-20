PORTNAME=	ktextaddons
DISTVERSION=	2.2.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Various text handling addons
WWW=		https://invent.kde.org/libraries/ktextaddons/

LICENSE=	LGPL20+

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		gettext cmake kde:6 python:run qt:6 shebangfix tar:xz xorg
USE_KDE=	archive colorscheme coreaddons i18n iconthemes \
		itemviews kio service sonnet \
		syntaxhighlighting textwidgets widgetsaddons \
		ecm:build
USE_QT=		base multimedia speech
USE_XORG=	x11

SHEBANG_FILES=	textedittexttospeech/kokoroinstall/scripts/kokoro_helper.py \
		textspeechtotext/speechtotext/whisperinstall/scripts/whisper_helper.py

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

.include <bsd.port.mk>
