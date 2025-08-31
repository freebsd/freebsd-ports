PORTNAME=	fotokilof
PORTVERSION=	5.1.8
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	GUI for ImageMagick and Wand
WWW=		https://github.com/TeaM-TL/FotoKilof

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}ttkbootstrap>=1.10.1:devel/py-ttkbootstrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fclist-cffi>=1.1.2:x11-fonts/py-fclist-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}FindSystemFontsFilename>=0.3.1:x11-fonts/py-FindSystemFontsFilename@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.5.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkcolorpicker>=2.1.3:graphics/py-tkcolorpicker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttkbootstrap>=1.10.1:devel/py-ttkbootstrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Wand>=0.6.11:graphics/py-wand@${PY_FLAVOR}

USES=		magick:run python
USE_GITHUB=	yes
GH_ACCOUNT=	TeaM-TL
GH_PROJECT=	FotoKilof

USE_PYTHON=	autoplist pep517

# fix Python wheel name (lower case)
post-patch:
	${REINPLACE_CMD} -E -e 's/^((__app)?name(__)? = )"${PORTNAME}"/\1"${PORTNAME}"/1i' \
		${WRKSRC}/fotokilof/version.py \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
