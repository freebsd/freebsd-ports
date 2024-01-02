PORTNAME=	fotokilof
PORTVERSION=	4.4.3
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FotoKilof-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	GUI for ImageMagick and Wand
WWW=		https://github.com/TeaM-TL/FotoKilof

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}ttkbootstrap>=1.10.1:devel/py-ttkbootstrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=9.5.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkcolorpicker>=2.1.3:graphics/py-tkcolorpicker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttkbootstrap>=1.10.1:devel/py-ttkbootstrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Wand>=0.6.11:graphics/py-wand@${PY_FLAVOR}

USES=		magick:run python

# the project really doesn't have PEP-517 support, but distutils/setuptools
# create a "wrong" entry_points script, so we use our pep517 feature
USE_PYTHON=	autoplist pep517

# fix Python wheel name (lower case)
post-patch:
	${REINPLACE_CMD} -e 's/\(__appname__ = \)"${PORTNAME}"/\1"${PORTNAME}"/1i' \
		${WRKSRC}/fotokilof/version.py

.include <bsd.port.mk>
