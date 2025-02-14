# When updating this port, also chase
#  devel/kdev-php
#  devel/kdev-python
PORTNAME=	kdevelop
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin extensible IDE for C/C++ and other languages
WWW=		https://www.kdevelop.org/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libKasten4Controllers.so:devel/okteta \
		libapr-1.so:devel/apr1 \
		libsvn_client-1.so:devel/subversion \
		libboost_thread.so:devel/boost-libs \
		libkomparediff2.so:textproc/libkomparediff2
RUN_DEPENDS=	gmake:devel/gmake

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:6 \
		llvm:build,run,noexport pkgconfig qt:6 shared-mime-info \
		shebangfix tar:xz xorg
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kdeclarative kio \
		libplasma newstuff notifications notifyconfig package parts \
		purpose runner service solid sonnet syntaxhighlighting \
		texteditor texttemplate textwidgets threadweaver \
		widgetsaddons windowsystem xmlgui
USE_QT=		base webengine
USE_XORG=	x11
SHEBANG_FILES=	kdevplatform/util/kdevplatform_shell_environment.sh \
		kdevplatform/util/.zshrc
# Most ports have ecm:build, testlib:build, but because this is an
# IDE, which **probably** is used for Qt / KDE development (also
# other things, but let's guess a target market), pull in some
# additional development things that are otherwise build-dep-only.
USE_KDE+=	ecm

CMAKE_ARGS=	-DCMAKE_POLICY_DEFAULT_CMP0074=NEW \
		-DClang_DIR=${LLVM_PREFIX}/lib/cmake/clang
CMAKE_OFF=	USE_QTWEBKIT

# Versioning values, to reduce plist churn
.include "${.CURDIR}/kdevelop.mk"

SHEBANG_LANG=	zsh
zsh_OLD_CMD=	/bin/zsh
zsh_CMD=	${LOCALBASE}/bin/zsh

.include <bsd.port.mk>
