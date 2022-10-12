PORTNAME=	pyxdg
DISTVERSION=	0.28
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyXDG is implementations of freedesktop.org standards in python
WWW=		https://freedesktop.org/wiki/Software/pyxdg/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils autoplist pytest # 2 tests fail, see https://gitlab.freedesktop.org/xdg/pyxdg/-/issues/26

NO_ARCH=	yes

.include <bsd.port.mk>
