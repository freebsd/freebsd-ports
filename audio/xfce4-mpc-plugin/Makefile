# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-mpc-plugin
PORTVERSION=	0.4.4
PORTREVISION=	4
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Musicpd client plugin for the Xfce panel 

LICENSE=	BSD

LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd
RUN_DEPENDS=	musicpd:${PORTSDIR}/audio/musicpd

USES=		gmake pkgconfig gettext
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libexo libmenu panel

.include <bsd.port.mk>
