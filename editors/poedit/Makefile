# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poedit
PORTVERSION=	1.0.3
CATEGORIES=	editors
MASTER_SITES=	http://www.volny.cz/v.slavik/poedit/

MAINTAINER=	ijliao@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

USE_GMAKE=	yes
WANT_GNOME=	yes

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS=	--without-gnome
.endif

.include <bsd.port.mk>
