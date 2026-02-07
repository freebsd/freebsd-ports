PORTNAME=	kdbg
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	devel kde

MAINTAINER=	thomas.sander@gmx.de
COMMENT=	Graphical user interface around gdb using KDE
WWW=		https://www.kdbg.org/

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lang kde:5 qt:5 xorg
USE_KDE=	auth codecs config configwidgets coreaddons ecm \
		i18n iconthemes widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	j6t

.include <bsd.port.mk>
