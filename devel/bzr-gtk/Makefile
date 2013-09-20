# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	bzr-gtk
PORTVERSION=	0.100.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/65442805/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	GTK interface to Bazaar-NG VCS

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr \
		${PYTHON_SITELIBDIR}/cairo:${PORTSDIR}/graphics/py-cairo

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GTKSOURCE
GTKSOURCE_DESC=	GTKSourceview support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKSOURCE}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtksourceview.so:${PORTSDIR}/x11-toolkits/py-gnome-desktop
.endif

.include <bsd.port.mk>
