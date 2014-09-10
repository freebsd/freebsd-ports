# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedink-dfarc
PORTVERSION=	3.10
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	freedink
DISTNAME=	dfarc-${PORTVERSION}

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Frontend and .dmod installer for GNU FreeDink

USES=		desktop-file-utils gettext gmake shared-mime-info
USE_WX=		2.8
WX_UNICODE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	intltool
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG} --disable-upx --disable-static
CONFIGURE_ENV+=	ac_cv_path_XDG_DESKTOP_MENU= ac_cv_path_XDG_ICON_RESOURCE= \
		ac_cv_path_XDG_MIME=

.include <bsd.port.mk>
