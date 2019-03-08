# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	kdbg
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	devel kde

MAINTAINER=	thomas.sander@gmx.de
COMMENT=	Graphical user interface around gdb using KDE

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lang kde:5 qt:5
USE_KDE=	auth codecs config configwidgets coreaddons ecm \
		i18n iconthemes widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui widgets xml \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	j6t

.include <bsd.port.mk>
