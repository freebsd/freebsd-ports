# New ports collection makefile for:	bzr-gtk
# Date created:		2007-03-04
# Whom:			Radim Kolar <hsn@sanatana.dharma>
#
# $FreeBSD$
#

PORTNAME=	bzr-gtk
PORTVERSION=	0.98.0
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/39697819/

MAINTAINER=	hsn@sendmail.cz
COMMENT=	GTK interface to Bazaar-NG VCS

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo \
		bzr:${PORTSDIR}/devel/bazaar-ng

USE_PYTHON=	2.4+
USE_GNOME=	pygtk2
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=	yes

OPTIONS=	GTKSOURCE "GTKSourceview support" OFF

do-patch:
		${REINPLACE_CMD} -e 's|/usr/share/olive/olive.glade|${PREFIX}/share/olive/olive.glade|' ${WRKSRC}/olive/guifiles.py
		${REINPLACE_CMD} -e 's|/usr/share/olive/cmenu.ui|${PREFIX}/share/olive/cmenu.ui|' ${WRKSRC}/olive/guifiles.py
		${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/olive-gtk.desktop

.include <bsd.port.pre.mk>

.if defined(WITH_GTKSOURCE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtksourceview.so:${PORTSDIR}/x11-toolkits/py-gnome-desktop
.endif

.include <bsd.port.post.mk>
