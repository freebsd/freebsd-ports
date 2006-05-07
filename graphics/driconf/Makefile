# New ports collection makefile for:    driconf
# Date created:         		1 Apr, 2005
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	driconf
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://dri.freedesktop.org/~fxkuehl/driconf/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	Configuration program for DRI drivers

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_PYTHON=	yes
NO_BUILD=	yes

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
