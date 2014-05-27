# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extra-extensions/Makefile 19693 2014-05-26 08:54:39Z gusi $

PORTNAME=	gnome-shell-extra-extensions
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome shell extra extensions metaport

RUN_DEPENDS=	gnome-shell-extension-weather>=0:${PORTSDIR}/deskutils/gnome-shell-extension-weather \
		gnome-shell-extension-openweather>=0:${PORTSDIR}/deskutils/gnome-shell-extension-openweather \
		gnome-shell-extension-panel-osd>=0:${PORTSDIR}/deskutils/gnome-shell-extension-panel-osd \
		gnome-shell-extension-mediaplayer>=0:${PORTSDIR}/deskutils/gnome-shell-extension-mediaplayer \
		gnome-shell-extensions-calculator>=0:${PORTSDIR}/deskutils/gnome-shell-extension-calculator \
		gnome-shell-extensions-coverflow>=0:${PORTSDIR}/deskutils/gnome-shell-extension-coverflow \
		gnome-shell-extension-overlay-icons>=0:${PORTSDIR}/deskutils/gnome-shell-extension-overlay-icons \
		gnome-shell-extension-hidetopbar>=0:${PORTSDIR}/deskutils/gnome-shell-extension-hidetopbar \
		gnome-shell-extension-lockkeys>=0:${PORTSDIR}/deskutils/gnome-shell-extension-lockkeys \
		gnome-shell-extension-trash>=0:${PORTSDIR}/deskutils/gnome-shell-extension-trash \
		gnome-shell-extension-dashtodock>=0:${PORTSDIR}/deskutils/gnome-shell-extension-dashtodock \
		gnome-shell-extension-audio-output-switcher>=0:${PORTSDIR}/deskutils/gnome-shell-extension-audio-output-switcher

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.mk>
