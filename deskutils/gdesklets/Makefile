# New ports collection makefile for:	gdesklets
# Date created:				11 August 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets
PORTVERSION=	0.20
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.pycage.de/download/${PORTNAME}/
DISTNAME=	gDesklets-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	A framework for Gnome 2.x for desktop applets

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
