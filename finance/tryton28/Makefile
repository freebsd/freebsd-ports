# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	tryton
PORTVERSION=	2.8.12
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP \
		http://downloads.tryton.org/2.8/
PKGNAMESUFFIX=	28

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Gtk+ Client)

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012:devel/py-pytz@${FLAVOR}

CONFLICTS=	tryton-2.[46].*

USES=		desktop-file-utils gettext python:2
USE_PYTHON=	distutils autoplist
USE_GNOME=	gtk20 pygtk2

PLIST_FILES=	share/applications/tryton.desktop share/pixmaps/tryton-icon.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/tryton.desktop ${STAGEDIR}${PREFIX}/share/applications/tryton.desktop
	${INSTALL_DATA} ${WRKSRC}/share/pixmaps/tryton/tryton-icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/tryton-icon.png

.include <bsd.port.mk>
