PORTNAME=	alkimia
PORTVERSION=	8.1.2
PORTREVISION=	2
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE financial data handling library
WWW=		https://community.kde.org/Alkimia/libalkimia

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Finance-Quote>=0:finance/p5-Finance-Quote \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-Writer>=0:textproc/p5-XML-Writer \
		p5-libwww>=0:www/p5-libwww

USES=		cmake compiler:c++11-lang kde:5 pathfix perl5 qt:5 \
		shebangfix tar:xz xorg
USE_LDCONFIG=	yes
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		i18n iconthemes jobwidgets kio newstuff service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui ecm:build
USE_PERL5=	run
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

PLIST_SUB=	VER=${PORTVERSION:R}
SHEBANG_FILES=	src/financequote.pl

OPTIONS_SINGLE=		MPLIB
OPTIONS_SINGLE_MPLIB=	GMP MPIR
OPTIONS_DEFINE=		PLASMA TEST TOOLS WEBENGINE
OPTIONS_DEFAULT=	MPIR TOOLS WEBENGINE
OPTIONS_SUB=		yes
MPLIB_DESC=		Multi-precision library (MPIR preferred)

GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CMAKE_BOOL=		CMAKE_DISABLE_FIND_PACKAGE_MPIR

MPIR_DESC=		MPIR (multiple precision arithmetic) support
MPIR_LIB_DEPENDS=	libmpir.so:math/mpir

PLASMA_DESC=		Build Plasma applets
PLASMA_USE=		KDE=package,plasma-framework
PLASMA_CMAKE_BOOL=	BUILD_APPLETS

TEST_USE=		QT=testlib
TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test

TOOLS_DESC=		Build tools
TOOLS_CMAKE_BOOL=	BUILD_TOOLS

WEBENGINE_DESC=		Webpage fetching and rendering
WEBENGINE_USE=		QT=location,printsupport,webchannel,webengine
WEBENGINE_CMAKE_BOOL=	BUILD_WITH_WEBENGINE

pre-configure:
	${FIND} ${WRKSRC} -type f \( -name '*.bak' -o -name '*.orig' \) -exec ${RM} {} \;

.include <bsd.port.mk>
