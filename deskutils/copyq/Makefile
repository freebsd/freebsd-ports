PORTNAME=	copyq
DISTVERSION=	17.0.0
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/hluk/CopyQ/releases/download/v${DISTVERSION}/
DISTNAME=	CopyQ-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Qt6 based clipboard manager
WWW=		https://github.com/hluk/CopyQ

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gl kde:6 pkgconfig qt:6 xorg
USE_GL=		opengl
USE_KDE=	guiaddons notifications statusnotifieritem ecm:build
USE_QT=		base declarative svg translations:build
USE_XORG=	ice sm x11 xext xfixes xtst

PORTSCOUT=	limit:^d\.d\.

OPTIONS_DEFINE=		AUDIO ENCRYPTION PLUGINS
OPTIONS_DEFAULT=	AUDIO ENCRYPTION PLUGINS
OPTIONS_SUB=		yes

AUDIO_DESC=		Audio notification support
ENCRYPTION_DESC=	Encrypt stored tabs

AUDIO_BUILD_DEPENDS=	${LOCALBASE}/include/miniaudio/miniaudio.h:audio/miniaudio
AUDIO_CMAKE_BOOL=	WITH_AUDIO
AUDIO_CMAKE_ON=		-DMINIAUDIO_INCLUDE_DIR=${LOCALBASE}/include/miniaudio

ENCRYPTION_LIB_DEPENDS=	libqca-qt6.so:devel/qca@qt6 \
			libqt6keychain.so:security/qtkeychain
ENCRYPTION_CMAKE_BOOL=	WITH_QCA_ENCRYPTION

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

.include <bsd.port.mk>
