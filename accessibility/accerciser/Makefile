PORTNAME=	accerciser
PORTVERSION=	3.48.0
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME
WWW=		https://gitlab.gnome.org/GNOME/accerciser

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		itstool:textproc/itstool
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}atspi>0:accessibility/py-atspi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome localbase:ldflags \
		meson pkgconfig python shebangfix tar:xz
USE_GNOME=	gtk30 pygobject3
GLIB_SCHEMAS=	org.a11y.Accerciser.gschema.xml
USE_PYTHON=	py3kplist

SHEBANG_FILES=	plugins/ipython_view.py
BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_CMD}|' \
		${WRKSRC}/src/accerciser.in \
		${WRKSRC}/src/wnck-window-infos.py

.include <bsd.port.mk>
