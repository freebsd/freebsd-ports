PORTNAME=	ManimPango
DISTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

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
USE_PYTHON=	pep517 cython autoplist pytest # tests fail to import manimpango, see https://github.com/ManimCommunity/ManimPango/issues/99
USE_GNOME=	cairo glib20 pango

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/manimpango/*${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
