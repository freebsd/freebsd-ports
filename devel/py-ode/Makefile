# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	ode
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyODE-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Python bindings for The Open Dynamics Engine

BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:devel/ode

USES=		python:2 tar:bzip2
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	TRIMESH
OPTIONS_DEFAULT=TRIMESH
TRIMESH_DESC=	Trimesh support (sync with OPCODE opt of devel/ode)

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.py

post-patch-TRIMESH-off:
	@${REINPLACE_CMD} -e '/TRIMESH_ENABLE/ s|True|False|' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ode.so

.include <bsd.port.mk>
