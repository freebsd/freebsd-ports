# New ports collection makefile for:	py-karaoke
# Date created:			8 October 2002
# Whom:				Elias Mandouvalos <ocean@mail.gr>
#
# $FreeBSD$
#

PORTNAME=	karaoke
PORTVERSION=	0.4.1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pykaraoke
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pykaraoke-${PORTVERSION}

MAINTAINER=	ocean@mail.gr
COMMENT=	Python karaoke application (Plays CD+G, MP3+G, OGG+G files)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24

USE_ZIP=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.mk>
