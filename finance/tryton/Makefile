# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	tryton
PORTVERSION=	2.4.16
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/2.4/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Gtk+ Client)

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012:${PORTSDIR}/devel/py-pytz

DEPRECATED=	Upstream project no longer supports the Tryton 2.4 series
EXPIRATION_DATE=	2015-08-05

CONFLICTS=	tryton28-2.8.*

USES=		cpe desktop-file-utils gettext python:2
USE_PYTHON=	distutils autoplist
USE_GNOME=	gtk20 pygtk2

PLIST_FILES=	share/applications/tryton.desktop share/pixmaps/tryton-icon.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/tryton.desktop ${STAGEDIR}${PREFIX}/share/applications/tryton.desktop
	${INSTALL_DATA} ${WRKSRC}/share/pixmaps/tryton/tryton-icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/tryton-icon.png

.include <bsd.port.mk>
