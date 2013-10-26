# $FreeBSD$

PORTNAME=	labyrinth
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Mind-mapping tool for GNOME

RUN_DEPENDS+=	f2py:${PORTSDIR}/math/py-numpy

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=msgfmt
USE_GNOME=	pygnome2 gnomedesktop gnomehack
USE_PYTHON=	yes
USES=		gettext gmake pkgconfig
INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
