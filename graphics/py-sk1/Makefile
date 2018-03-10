# $FreeBSD$

PORTNAME=	sk1
DISTVERSION=	g20171127
PORTREVISION=	2
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Professional quality illustration program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libMagickCore-6.so:graphics/ImageMagick
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycups>0:print/py-pycups@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${FLAVOR}

USES=		desktop-file-utils python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	sk1project
GH_PROJECT=	sk1-wx
GH_TAGNAME=	2352d72
USE_PYTHON=	concurrent distutils
PYSETUP=	setup-sk1.py
PYDISTUTILS_INSTALLARGS=	--root=${STAGEDIR}
USE_GNOME=	cairo glib20 pango
USE_WX=		2.8+ # 2.8 or 3.0 (see the github page)
WX_COMPS=	python:lib

MAKE_ENV=	FREEBSD_PYTHON_VER=${PYTHON_VER}
_VER=		"2.0rc3"
PLIST_SUB=	VER="${_VER}"

post-patch:
	@${REINPLACE_CMD} -E " \
		s|/usr/|${LOCALBASE}/|g ; \
		s|%s-wx-%s' % \(NAME, VERSION\)|%s-wx-%s-%s' % (NAME, VERSION, os.environ['FREEBSD_PYTHON_VER'])| ; \
		s/sk1\.(desktop|png|xpm|svg)/sk1-${PYTHON_VER}.\1/g ; \
		s|\(install_path, \['GPLv3.txt', 'LICENSE', \]\),|| " \
		${WRKSRC}/setup-sk1.py
	@${REINPLACE_CMD} -e 's|/usr/|${LOCALBASE}/|' ${WRKSRC}/setup.cfg_*
	@${REINPLACE_CMD} -e ' \
		s|sk1|sk1-${PYTHON_VER}| ; \
		s|^Name.*|& (python${PYTHON_VER})|' \
		${WRKSRC}/src/sk1.desktop
.for ext in desktop png xpm svg
	@${MV} ${WRKSRC}/src/sk1.${ext} ${WRKSRC}/src/sk1-${PYTHON_VER}.${ext}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sk1-wx-${_VER}-${PYTHON_VER}/uc2/*/_*.so

.include <bsd.port.mk>
