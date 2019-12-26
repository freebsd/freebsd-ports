# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	bzr-gtk
PORTVERSION=	0.100.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/65442805/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK interface to Bazaar-NG VCS

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:devel/bzr
RUN_DEPENDS=	bzr:devel/bzr \
		${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}

USES=		desktop-file-utils gnome python:2.7
USE_PYTHON=	distutils autoplist
USE_GNOME=	pygtk2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GTKSOURCE
GTKSOURCE_DESC=	GTKSourceview support

GTKSOURCE_USE=	GNOME=pygnomedesktop

.include <bsd.port.mk>
