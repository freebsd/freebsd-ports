# New ports collection makefile for:	bzr-gtk
# Date created:		2007-03-04
# Whom:			Radim Kolar <hsn@sanatana.dharma>
#
# $FreeBSD$
#

PORTNAME=	bzr-gtk
PORTVERSION=	0.99.0
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/53657034/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	GTK interface to Bazaar-NG VCS

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo \
		bzr:${PORTSDIR}/devel/bazaar-ng

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=	yes

OPTIONS=	GTKSOURCE "GTKSourceview support" OFF

.include <bsd.port.pre.mk>

.if defined(WITH_GTKSOURCE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtksourceview.so:${PORTSDIR}/x11-toolkits/py-gnome-desktop
.endif

.include <bsd.port.post.mk>
