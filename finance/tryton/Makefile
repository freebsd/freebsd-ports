# New ports collection makefile for:	tryton
# Date created:				12 August, 2012
# Whom:					Matthias Petermann<matthias@petermann.it>
#
# $FreeBSD$
#

PORTNAME=	tryton
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/2.4/

MAINTAINER=	matthias@petermann.it
COMMENT=	The Tryton Gtk+ client

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012:${PORTSDIR}/devel/py-pytz

USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install
USE_GNOME=	gtk20 desktopfileutils pygtk2

post-install:
	${INSTALL_DATA} ${WRKSRC}/tryton.desktop ${PREFIX}/share/applications/tryton.desktop
	${INSTALL_DATA} ${WRKSRC}/share/pixmaps/tryton/tryton-icon.png ${PREFIX}/share/pixmaps/tryton-icon.png
	-@update-desktop-database

.include <bsd.port.mk>
