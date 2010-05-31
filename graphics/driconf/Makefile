# New ports collection makefile for:    driconf
# Date created:         		1 Apr, 2005
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	driconf
PORTVERSION=	0.9.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://people.freedesktop.org/~fxkuehl/driconf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configuration program for DRI drivers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_GL=		glut
USE_PYTHON=	yes
NO_BUILD=	yes
USE_GETTEXT=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFODIR=	lib/driconf

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
