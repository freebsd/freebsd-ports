PORTNAME=	KVIrc
DISTVERSION=	5.2.8
CATEGORIES=	irc kde

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	IRC client based on the Qt GUI toolkit
WWW=		https://www.kvirc.net

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/ABOUT-LICENSE

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gl pkgconfig \
		qt:6 ssl xorg
USE_GITHUB=	yes
USE_GL=		opengl
USE_LDCONFIG=	yes
USE_QT=		5compat base multimedia
USE_XORG=	ice sm x11 xext xrender xscrnsaver

CMAKE_ARGS=	-DQT_VERSION_MAJOR=6
CMAKE_ON=	WANT_CRYPT WANT_IPC WANT_IPV6 WANT_OPENSSL WANT_OSS WANT_STRIP \
		WANT_TRANSPARENCY
CMAKE_OFF=	WANT_COEXISTENCE WANT_DEBUG WANT_ENV_FLAGS \
		WANT_IGNORE_SIGALARM WANT_MEMORY_CHECKS WANT_MEMORY_PROFILE

PLIST_SUB=	FULL_VER="${DISTVERSION}" \
		VER="${DISTVERSION:R}"

OPTIONS_DEFINE=		AUDIOFILE DBUS DCC_VIDEO DCC_VOICE DOCS DOXYGEN ENCHANT GSM \
			KDE OGG PERL PHONON PYTHON NLS SVG WEBENGINE
OPTIONS_DEFAULT=	AUDIOFILE DBUS DCC_VOICE ENCHANT GSM KDE OGG PERL PHONON \
			PYTHON SVG WEBENGINE
OPTIONS_SUB=		yes

DCC_VIDEO_DESC=		Direct client video connection support (experimental)
DCC_VOICE_DESC=		Direct client voice connection support

AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile
AUDIOFILE_CMAKE_BOOL=	WANT_AUDIOFILE

DBUS_CMAKE_BOOL=	WANT_QTDBUS

DCC_VIDEO_CMAKE_BOOL=	WANT_DCC_VIDEO

DCC_VOICE_CMAKE_BOOL=	WANT_DCC_VOICE

DOCS_USES=		perl5
DOCS_USE=		perl5:build
DOCS_CMAKE_BOOL=	WANT_PERL_DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	WANT_DOXYGEN

ENCHANT_LIB_DEPENDS=	libenchant-2.so:textproc/enchant2
ENCHANT_CMAKE_BOOL=	WANT_SPELLCHECKER

# Used via dlopen()
GSM_RUN_DEPENDS=	${LOCALBASE}/lib/libgsm.so:audio/gsm
GSM_CMAKE_BOOL=		WANT_GSM

KDE_USES=		kde:6
KDE_USE=		kde=colorscheme,completion,config,configwidgets \
			kde=coreaddons,guiaddons,i18n,jobwidgets,kio \
			kde=notifications,parts,service,statusnotifieritem \
			kde=widgetsaddons,windowsystem,xmlgui,ecm:build
KDE_CMAKE_BOOL=		WANT_KDE

NLS_USES=		gettext-tools
NLS_CMAKE_BOOL=		WANT_GETTEXT

OGG_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis \
			libtheoradec.so:multimedia/libtheora
OGG_CMAKE_BOOL=		WANT_OGG_THEORA

PERL_USES=		perl5
PERL_USE=		perl5:run
PERL_CMAKE_BOOL=	WANT_PERL

PHONON_USES=		kde:6
PHONON_USE=		kde=phonon
PHONON_CMAKE_BOOL=	WANT_PHONON

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	WANT_PYTHON

SVG_USE=		qt=svg
SVG_CMAKE_BOOL=		WANT_QTSVG

WEBENGINE_USE=		qt=declarative,positioning,webchannel,webengine
WEBENGINE_CMAKE_BOOL=	WANT_QTWEBENGINE

.include <bsd.port.mk>
