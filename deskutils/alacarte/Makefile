# New ports collection makefile for:	menueditor
# Date created:				22 March 2005
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#

PORTNAME=	alacarte
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://dev.realistanew.com/${PORTNAME}/releases/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An editor for the freedesktop.org menu specification

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

USE_GNOME=	pygtk2 pygnome2
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --install-lib=${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
