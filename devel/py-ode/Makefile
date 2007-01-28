# New ports collection makefile for:	py-ode
# Date created:		26 Jan 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	ode
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyode
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyODE-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Python bindings for The Open Dynamics Engine

BUILD_DEPENDS=	${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode

USE_BZIP2=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
	@${REINPLACE_CMD} -e '/^#ODE_BASE/ s|.*|ODE_BASE="${X11BASE}"|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
