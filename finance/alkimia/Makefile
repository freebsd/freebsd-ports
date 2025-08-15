PORTNAME=	alkimia
PORTVERSION=	8.2.1
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE financial data handling library
WWW=		https://community.kde.org/Alkimia/libalkimia

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libmpir.so:math/mpir
RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Finance-Quote>=0:finance/p5-Finance-Quote \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-Writer>=0:textproc/p5-XML-Writer \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	appstreamcli:devel/appstream

USES=		cmake:testing compiler:c++17-lang gettext-tools gl kde:6 \
		pathfix perl5 qt:6 shebangfix tar:xz xorg
USE_GL=		opengl
USE_KDE=	attica codecs completion config coreaddons i18n iconthemes \
		newstuff sonnet textwidgets widgetsaddons \
		ecm:build
USE_LDCONFIG=	yes
USE_PERL5=	run
USE_QT=		base declarative \
		tools:build
USE_XORG=	x11

SHEBANG_FILES=	src/financequote.pl

CMAKE_ARGS=	-DQT_MAJOR_VERSION:STRING="6"
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen
# The WebEngine tests need a running X11/Wayland session to succeed.
# SETENVI strips out important environment variables like DISPLAY.
CMAKE_TESTING_SETENV=	yes

# Qt needs a resonable TZ environment variable set to calculate offsets
# properly. Date/time tests will fail if TZ is otherwise undefined.
TEST_ENV=	TZ="UTC"

PLIST_SUB=	ALK_VER=${PORTVERSION:R} \
		ALK_VERSION=${PORTVERSION}

OPTIONS_DEFINE=		PLASMA TOOLS
OPTIONS_DEFINE_aarch64=	WEBENGINE
OPTIONS_DEFINE_amd64=	WEBENGINE
OPTIONS_DEFINE_armv7=	WEBENGINE
OPTIONS_DEFINE_i386=	WEBENGINE
OPTIONS_DEFAULT=	TOOLS
OPTIONS_DEFAULT_aarch64=WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_armv7=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE
OPTIONS_SUB=		yes

PLASMA_DESC=		Build Plasma applets
PLASMA_USE=		KDE=libplasma,package
PLASMA_CMAKE_BOOL=	BUILD_APPLETS

TOOLS_DESC=		Build tools
TOOLS_USE=		KDE=colorscheme,configwidgets,guiaddons,xmlgui
TOOLS_CMAKE_BOOL=	BUILD_TOOLS

WEBENGINE_DESC=		Webpage fetching and rendering
WEBENGINE_USE=		QT=positioning,webchannel,webengine
WEBENGINE_CMAKE_BOOL=	BUILD_WITH_WEBENGINE

pre-configure:
# ${FILESDIR}/plasma_applets_ForeignCurrencies_metadata.json was generated using
# the desktoptojson utility from devel/kf5-kcoreaddons:
# `desktoptojson -i ${WRKSRC}/plasma/applets/ForeignCurrencies/metadata.desktop`
# The desktoptojson utility no longer ships with KF6, as support for .desktop
# files for this purpose was deprecated in KF 5.104.0 (2023-03-11) and removed
# in KF6. The pre-generated JSON file avoids pulling in Qt5/KF5.
	${CP} ${FILESDIR}/plasma_applets_ForeignCurrencies_metadata.json ${WRKSRC}/plasma/applets/ForeignCurrencies/metadata.json

.include <bsd.port.mk>
