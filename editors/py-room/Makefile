# New ports collection makefile for:	py-room
# Date created:		2009-11-11
# Whom:			Alexander Best
#
# $FreeBSD$
#

PORTNAME=	room
PORTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	editors python
MASTER_SITES=	https://launchpad.net/pyroom/${PORTVERSION:R}/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	alexbestms@wwu.de
COMMENT=	PyRoom is a clone of WriteRoom and features "distraction-free writing"

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

FETCH_ARGS=
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyRoom

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' \
			${WRKSRC}/setup.py ${WRKSRC}/PyRoom/preferences.py \
			${WRKSRC}/PyRoom/gui.py ${WRKSRC}/pyroom.desktop

.include <bsd.port.mk>
