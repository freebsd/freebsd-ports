# New ports collection makefile for:	xmms-gdancer
# Date created:			2. Jul 2001
# Whom:				Alexander@Leidinger.net
#
# $FreeBSD$
#

PORTNAME=	xmms-gdancer
PORTVERSION=	0.4.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.figz.com/gdancer/files/
DISTNAME=	gdancer-$(PORTVERSION)

MAINTAINER=	netchild@FreeBSD.org

LIB_DEPENDS=	xmms.3:${PORTSDIR}/multimedia/xmms \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-pixbuf

post-install:
	-${RM} ${PREFIX}/lib/xmms/Visualization/gdancer.la
	@${ECHO_CMD} +++
	@${ECHO_CMD} Now you have to install some themes from http://www.figz.com/gdancer/themes.php
	@${ECHO_CMD} into .xmms/gdancer_themes. If it does not exist in your HOME directory, just
	@${ECHO_CMD} create it.

.include <bsd.port.mk>
