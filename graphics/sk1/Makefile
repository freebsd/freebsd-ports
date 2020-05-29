# $FreeBSD$

PORTNAME=	sk1
DISTVERSION=	2.0
DISTVERSIONSUFFIX=	rc3
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	https://downloads.sk1project.net/sk1/${DISTVERSIONFULL}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Professional quality illustration program

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPLv3.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libMagickCore-6.so:graphics/ImageMagick6
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pycups1>0:print/py-pycups1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

USES=		desktop-file-utils gettext gnome python:2.7 shebangfix
SHEBANG_FILES=	${PYSETUP}
USE_PYTHON=	distutils distutils
PYSETUP=	setup-sk1.py
PYDISTUTILS_INSTALLARGS=	--root=${STAGEDIR}
USE_GNOME=	cairo glib20 pango
USE_WX=		3.0+
WX_COMPS=	python:lib
INSTALLS_ICONS=	yes

MAKE_ENV=	FREEBSD_PYTHON_VER=${PYTHON_VER}
_VER=		${DISTVERSIONFULL}
PLIST_SUB=	VER="${_VER}"

post-patch:
	@${REINPLACE_CMD} -E " \
		s,/usr/(bin|include|lib|share),${LOCALBASE}/\1,g ; \
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
