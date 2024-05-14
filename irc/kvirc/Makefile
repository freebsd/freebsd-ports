PORTNAME=	KVIrc
DISTVERSION=	5.2.4
CATEGORIES=	irc kde

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	IRC client based on the Qt GUI toolkit
WWW=		https://www.kvirc.net

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/ABOUT-LICENSE

USES=		cmake compiler:c++11-lang cpe desktop-file-utils pkgconfig qt:5 \
		ssl xorg
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		concurrent core declarative gui multimedia network printsupport \
		sql widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext xrender xscrnsaver

CMAKE_ARGS=	-DQT_VERSION_MAJOR=5
CMAKE_ON=	WANT_CRYPT WANT_IPC WANT_IPV6 WANT_OPENSSL WANT_OSS WANT_STRIP \
		WANT_TRANSPARENCY
CMAKE_OFF=	WANT_COEXISTENCE WANT_DEBUG WANT_ENV_FLAGS WANT_ESD \
		WANT_IGNORE_SIGALARM WANT_MEMORY_CHECKS WANT_MEMORY_PROFILE

PLIST_SUB=	FULL_VER="${DISTVERSION}" \
		VER="${DISTVERSION:R}"

OPTIONS_DEFINE=		AUDIOFILE DBUS DCC_VIDEO DCC_VOICE DOCS DOXYGEN ENCHANT GSM \
			GTKSTYLE KDE OGG PERL PHONON PYTHON NLS SVG WEBENGINE
OPTIONS_DEFAULT=	AUDIOFILE DBUS DCC_VOICE ENCHANT GSM KDE OGG PERL PHONON \
			PYTHON SVG WEBENGINE
OPTIONS_SUB=		yes

DCC_VIDEO_DESC=		Direct client video connection support (experimental)
DCC_VOICE_DESC=		Direct client voice connection support
GTKSTYLE_DESC=		Enable QGtkStyle

AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile
AUDIOFILE_CMAKE_BOOL=	WANT_AUDIOFILE

DBUS_USE=		qt=dbus
DBUS_CMAKE_BOOL=	WANT_QTDBUS

DCC_VIDEO_CMAKE_BOOL=	WANT_DCC_VIDEO
DCC_VIDEO_BROKEN=	qt5 support dropped: https://github.com/kvirc/KVIrc/pull/2628

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

GTKSTYLE_CMAKE_BOOL=	WANT_GTKSTYLE

KDE_IMPLIES=		DBUS
KDE_USES=		kde:5
KDE_USE=		kde=auth,codecs,completion,config,configwidgets,coreaddons,i18n \
			kde=jobwidgets,kio,notifications,parts,phonon,service,solid \
			kde=sonnet,textwidgets,widgetsaddons,windowsystem,xmlgui,ecm:build
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

PHONON_USES=		kde:5
PHONON_USE=		kde=phonon
PHONON_CMAKE_BOOL=	WANT_PHONON

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	WANT_PYTHON

SVG_USE=		qt=svg
SVG_CMAKE_BOOL=		WANT_QTSVG

WEBENGINE_USE=		qt=location,webchannel,webengine
WEBENGINE_CMAKE_BOOL=	WANT_QTWEBENGINE

.include <bsd.port.mk>
