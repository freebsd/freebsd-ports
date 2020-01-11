# $FreeBSD$

# When updating this port, also chase
#  devel/kdev-php
#  devel/kdev-python
PORTNAME=	kdevelop
DISTVERSION=	5.4.6
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/kdevelop/${DISTVERSION}/src
DIST_SUBDIR=	KDE/kdevelop

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin extensible IDE for C/C++ and other languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt \
		llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libKasten4Controllers.so:devel/okteta \
		libapr-1.so:devel/apr1 \
		libsvn_client-1.so:devel/subversion \
		libboost_thread.so:devel/boost-libs \
		libkomparediff2.so:textproc/libkomparediff2
RUN_DEPENDS=	gmake:devel/gmake \
		llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gettext grantlee:5 kde:5 qt:5 shared-mime-info shebangfix tar:xz
USE_KDE=	archive attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons emoticons i18n iconthemes init \
		itemmodels itemviews jobwidgets kcmutils kdeclarative \
		kio libksysguard newstuff notifications \
		notifyconfig package parts plasma-framework purpose \
		runner service solid sonnet texteditor textwidgets threadweaver \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui help network \
		script sql widgets xml buildtools_build qmake_build
CONFLICTS=	kdevelop-kde4-4* kdevelop-4* kdevplatform-kde4-4* kdevplatform-4*
SHEBANG_FILES=	kdevplatform/util/kdevplatform_shell_environment.sh \
		kdevplatform/util/.zshrc

CMAKE_ARGS=	-DCMAKE_POLICY_DEFAULT_CMP0074=NEW -DLLVM_ROOT=${LOCALBASE}/llvm${LLVM_DEFAULT}

# Versioning values, to reduce plist churn
PLATFORM_VER=	32
SO_VER=		54
PLIST_SUB+=	PLATFORM_VER=${PLATFORM_VER} SO_VER=${SO_VER} SO_VER_LONG=${DISTVERSION}

OPTIONS_DEFINE=	WEBENGINE
WEBENGINE_DESC=	Use WebEngine as help reader
WEBENGINE_USES=	qt:5
WEBENGINE_USE=	QT=location,webchannel,webengine
WEBENGINE_USE_OFF=	QT=webkit
WEBENGINE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets:BOOL=TRUE

SHEBANG_LANG=	zsh
zsh_OLD_CMD=	/bin/zsh
zsh_CMD=	${LOCALBASE}/bin/zsh

.include <bsd.port.mk>
