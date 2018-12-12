# $FreeBSD$

PORTNAME=	pysofa
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	astro devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for SOFA, the fundamental astronomy library

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/lib/libsofa_c.so:astro/sofa \
		${PYNUMPY}

USES=		python
NO_ARCH=	yes
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e "s|find_library('sofa_c')|\"${LOCALBASE}/lib/libsofa_c.so\"|" \
		${WRKSRC}/pysofa/pysofa_ctypes.py

.include <bsd.port.mk>
