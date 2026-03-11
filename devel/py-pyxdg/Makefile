PORTNAME=	pyxdg
PORTVERSION=	0.28
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://gitlab.freedesktop.org/xdg/pyxdg/-/commit/
PATCHFILES=	275865e620471c194560824232be632c9cb61600.patch:-p1 \
		9291d419017263c922869d79ac1fe8d423e5f929.patch:-p1 \
		63033ac306aa26d32e1439417e59ae8f8a4c9820.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python library to access freedesktop.org standards
WWW=		https://freedesktop.org/wiki/Software/pyxdg/

LICENSE=	LGPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/xdg/BaseDirectory.py

.include <bsd.port.mk>
