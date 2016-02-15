# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-utils
PORTVERSION=	3.18.0
PORTEPOCH=	1
CATEGORIES=	deskutils gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 support utilities

USES=		metaport

RUN_DEPENDS=	baobab>=3.0:${PORTSDIR}/deskutils/baobab \
		gnome-screenshot>=3.0:${PORTSDIR}/deskutils/gnome-screenshot \
		gnote>=3.0:${PORTSDIR}/deskutils/gnote \
		gnome-contacts>=3.0:${PORTSDIR}/deskutils/gnome-contacts \
		gnome-search-tool>=3.0:${PORTSDIR}/deskutils/gnome-search-tool \
		gnome-dictionary>=3.0:${PORTSDIR}/deskutils/gnome-dictionary \
		gnome-system-log>=3.0:${PORTSDIR}/deskutils/gnome-system-log \
		gnome-font-viewer>=3.0:${PORTSDIR}/deskutils/gnome-font-viewer \
		gnome-system-monitor>=3.0:${PORTSDIR}/sysutils/gnome-system-monitor \
		gnome-photos>=3.0:${PORTSDIR}/deskutils/gnome-photos \
		gnome-clocks>=3.0:${PORTSDIR}/deskutils/gnome-clocks \
		gnome-maps>=3.0:${PORTSDIR}/deskutils/gnome-maps \
		gnome-weather>=3.0:${PORTSDIR}/deskutils/gnome-weather \
		gnome-todo>=3.0:${PORTSDIR}/deskutils/gnome-todo

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Build Gnome Documents (pulls in tracker)

DOCS_RUN_DEPENDS+=	gnome-documents>=0:${PORTSDIR}/deskutils/gnome-documents

.include <bsd.port.mk>
