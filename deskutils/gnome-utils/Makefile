PORTNAME=	gnome-utils
PORTVERSION=	42
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME support utilities

USES=		metaport

RUN_DEPENDS=	baobab>=3.0:deskutils/baobab \
		gnome-screenshot>=3.0:deskutils/gnome-screenshot \
		gnote>=3.0:deskutils/gnote \
		gnome-contacts>=3.0:deskutils/gnome-contacts \
		gnome-dictionary>=3.0:deskutils/gnome-dictionary \
		gnome-font-viewer>=3.0:deskutils/gnome-font-viewer \
		gnome-system-monitor>=3.0:sysutils/gnome-system-monitor \
		gnome-calendar>=3.0:deskutils/gnome-calendar \
		gnome-photos>=3.0:deskutils/gnome-photos \
		gnome-clocks>=3.0:deskutils/gnome-clocks \
		gnome-maps>=3.0:deskutils/gnome-maps \
		gnome-weather>=3.0:deskutils/gnome-weather
		# Temporarily disabled due to build errors, see PR 257667
		#gnome-todo>=3.0:deskutils/gnome-todo

.include <bsd.port.mk>
