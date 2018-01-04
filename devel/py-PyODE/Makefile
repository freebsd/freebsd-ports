# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	PyODE
PORTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Python bindings for The Open Dynamics Engine

LICENSE=	LGPL21+ BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE-BSD

LIB_DEPENDS=	libode.so:devel/ode

USES=		python:2.7
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	TRIMESH
OPTIONS_DEFAULT=TRIMESH
TRIMESH_DESC=	Trimesh support (sync with OPCODE opt of devel/ode)

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.py

post-patch-TRIMESH-off:
	@${REINPLACE_CMD} -e '/TRIMESH_ENABLE/ s|True|False|' ${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ode.so

.include <bsd.port.mk>
