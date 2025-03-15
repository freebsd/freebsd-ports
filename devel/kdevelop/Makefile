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

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libsvn_client-1.so:devel/subversion \
		libkomparediff2.so:textproc/libkomparediff2
RUN_DEPENDS=	gmake:devel/gmake

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools gl \
		kde:6 llvm:build,run,noexport pkgconfig qt:6 shared-mime-info \
		shebangfix tar:xz xorg
USE_GL=		gl opengl # GLX
USE_KDE=	archive attica bookmarks codecs colorscheme completion config \
		configwidgets coreaddons crash guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kio \
		libplasma newstuff notifications notifyconfig parts \
		purpose runner service solid sonnet syntaxhighlighting \
		texteditor texttemplate textwidgets threadweaver \
		widgetsaddons windowsystem xmlgui
USE_QT=		5compat base declarative positioning tools webchannel webengine
USE_XORG=	x11

SHEBANG_FILES=	kdevplatform/util/kdevplatform_shell_environment.sh \
		kdevplatform/util/.zshrc
SHEBANG_LANG=	zsh
zsh_OLD_CMD=	/bin/zsh
zsh_CMD=	${LOCALBASE}/bin/zsh

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

.include <bsd.port.mk>
