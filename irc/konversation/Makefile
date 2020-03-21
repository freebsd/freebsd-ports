# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	konversation
PORTVERSION=	1.7.5
PORTREVISION=	6
CATEGORIES=	irc kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User friendly IRC client for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		python:run qca qt:5 shebangfix tar:xz
USE_KDE=	archive auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons doctools ecm \
		emoticons globalaccel i18n iconthemes idletime itemviews \
		jobwidgets kio notifications notifyconfig parts service solid \
		sonnet textwidgets wallet widgetsaddons windowsystem xmlgui \
		init_run
USE_QT=		concurrent core dbus gui network phonon4 widgets xml \
		buildtools_build qmake_build

SHEBANG_FILES=	data/scripts/bug \
		data/scripts/cmd \
		data/scripts/mail \
		data/scripts/media \
		data/scripts/sayclip \
		data/scripts/sysinfo \
		data/updaters/*.pl

.include <bsd.port.mk>
