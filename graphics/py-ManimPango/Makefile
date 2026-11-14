PORTNAME=	ManimPango
DISTVERSION=	0.7.1
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bindings for Pango for use with Manim
WWW=		https://manimpango.manim.community/en/latest/

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gettext-runtime gnome pkgconfig python
USE_PYTHON=	pep517 cython autoplist pytest
USE_GNOME=	cairo glib20 pango

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload --import-mode=importlib --deselect tests/test_fonts.py::test_warning # test_warning is only skipped on Linux, uses cwd import shadowing the staged module

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/manimpango/*${PYTHON_TAG}.so

# tests as of 0.7.1: 38 passed, 3 skipped, 3 deselected in 0.06s

.include <bsd.port.mk>
