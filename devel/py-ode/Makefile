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
# gcc4x compatibility
	@${REINPLACE_CMD} -e 's|((PyObject *\*)__pyx_v_sp) = |__pyx_v_sp = (struct __pyx_obj_3ode_SpaceBase*)|' ${WRKSRC}/ode_notrimesh.c
	@${REINPLACE_CMD} -e 's|((PyObject *\*)__pyx_v_m) = |__pyx_v_m = (struct __pyx_obj_3ode_Mass*)|' ${WRKSRC}/ode_notrimesh.c
	@${REINPLACE_CMD} -e 's|((PyObject *\*)__pyx_v_jg) = |__pyx_v_jg = (struct __pyx_obj_3ode_JointGroup*)|' ${WRKSRC}/ode_notrimesh.c
	@${REINPLACE_CMD} -e 's|((PyObject *\*)__pyx_v_cont) = |__pyx_v_cont = (struct __pyx_obj_3ode_Contact*)|' ${WRKSRC}/ode_notrimesh.c

.include <bsd.port.mk>
