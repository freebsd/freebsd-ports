# $FreeBSD$

PORTNAME=	kdeconnect-kde
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for KDE to interface between your phone and your computer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfakekey.so:x11/libfakekey \
		libKF5PulseAudioQt.so:audio/pulseaudio-qt
BUILD_DEPENDS=	kpeoplevcard>0:net/kpeoplevcard
RUN_DEPENDS=	sshpass:security/sshpass \
		sshfs:sysutils/fusefs-sshfs \
		kpeoplevcard>0:net/kpeoplevcard


USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		pkgconfig qca qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons doctools ecm i18n iconthemes \
		itemviews jobwidgets kcmutils kio kirigami2 notifications \
		people service solid wayland widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui multimedia network \
		testlib widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xtst
USE_LDCONFIG=	${QT_QMLDIR}/org/kde/kdeconnect

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
