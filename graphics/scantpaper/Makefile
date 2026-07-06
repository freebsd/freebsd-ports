PORTNAME=	scantpaper
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.10
CATEGORIES=	graphics python

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	GUI to produce PDFs or DjVus from scanned documents
WWW=		https://github.com/carygravel/scantpaper

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polib>0:devel/py-polib@${PY_FLAVOR}
LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpoppler.so:graphics/poppler \
		libgoocanvas-2.0.so:graphics/goocanvas2
RUN_DEPENDS=	unpaper:graphics/unpaper \
		${PYTHON_PKGNAMEPREFIX}img2pdf>0:graphics/py-img2pdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tesserocr>0:graphics/py-tesserocr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ocrmypdf>=15.4.3:textproc/py-ocrmypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-iso639>0:textproc/py-python-iso639@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sane>0:graphics/py-sane@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		compiler:c++17-lang gettext gnome magick:build,run python
USE_GITHUB=	yes
GH_ACCOUNT=	carygravel
USE_GNOME=	cairo gdkpixbuf gtk30 introspection librsvg2 pygobject3
USE_PYTHON=	pep517
NO_ARCH=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-build:
	(cd ${WRKSRC} ; python3.12 dev/compile_mo.py --src po --out locale --domain scantpaper)

post-install:
	(cd ${WRKSRC} ; for mo in locale/*/LC_MESSAGES/scantpaper.mo ; do ${MKDIR} "${STAGEDIR}/${PREFIX}/share/$$(dirname $${mo})" ; ${INSTALL_DATA} "$${mo}" "${STAGEDIR}/${PREFIX}/share/$$(dirname $${mo})/" ; done)

.include <bsd.port.mk>
