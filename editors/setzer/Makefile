PORTNAME=	setzer
DISTVERSIONPREFIX=	v
DISTVERSION=	66
PORTREVISION=	4
CATEGORIES=	editors
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	LaTeX editor written in Python with Gtk
WWW=		https://www.cvfosammmm.org/setzer/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libgspell-1.so:textproc/gspell \
		libpoppler-glib.so:graphics/poppler-glib \
		libportal.so:deskutils/libportal \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bibtexparser>0:textproc/py-bibtexparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=0:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		tex-xetex>0:print/tex-xetex \
		xdg-open:devel/xdg-utils

USES=		desktop-file-utils gettext gnome meson pkgconfig python \
		shared-mime-info shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	cvfosammmm
GH_PROJECT=	Setzer
USE_GNOME=	glib20 gtk40 gtksourceview5 introspection pango pygobject3
USE_PYTHON=	flavors py3kplist

SHEBANG_FILES=	scripts/*
NO_ARCH=	yes

.include <bsd.port.mk>
