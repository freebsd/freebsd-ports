# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	tryton
PORTVERSION=	2.4.7
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/2.4/

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Gtk+ Client)

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012:${PORTSDIR}/devel/py-pytz

CONFLICTS=	tryton-2.[68].*

USES=		desktop-file-utils gettext
USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install
USE_GNOME=	gtk20 pygtk2

post-install:
	${INSTALL_DATA} ${WRKSRC}/tryton.desktop ${STAGEDIR}${PREFIX}/share/applications/tryton.desktop
	${INSTALL_DATA} ${WRKSRC}/share/pixmaps/tryton/tryton-icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/tryton-icon.png

.include <bsd.port.mk>
