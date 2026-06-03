PORTNAME=	pypillowfight
DISTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library containing various image processing algorithms
WWW=		https://gitlab.gnome.org/World/OpenPaperwork/libpillowfight

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:devel/py-nose@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
