# Created by: Jonathan Anderson <jonathan@FreeBSD.org>
# $FreeBSD$

PORTNAME=		git-cola
DISTVERSIONPREFIX=	v
DISTVERSION=		3.5
CATEGORIES=		devel

MAINTAINER=		dch@FreeBSD.org
COMMENT=		Sleek and powerful Git GUI

LICENSE=		GPLv2+
LICENSE_FILE=		${WRKSRC}/COPYING

BUILD_DEPENDS=		git>=0:devel/git
RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}QtPy>=1.7.1:devel/py-QtPy@${PY_FLAVOR}

USES=			desktop-file-utils gmake gnome python pyqt:5 qt:5 shebangfix
USE_GITHUB=		yes
USE_PYQT=		core gui network widgets

SHEBANG_FILES=		share/git-cola/bin/git-xbase
INSTALLS_ICONS=		yes
NO_ARCH=		yes

# NO_VENDOR_LIBS ensures we use ports QtPy not embedded version
MAKE_ARGS=		prefix=${PREFIX} PYTHON=${PYTHON_CMD} NO_VENDOR_LIBS=1

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e 's|LN_S = $$(LN) -s -f|LN_S = ${RLN}|;\
s|$$(LN_S) "$$(datadir)/icons/git-cola.svg"|$$(LN_S) \
"$$(DESTDIR)$$(datadir)/icons/git-cola.svg"|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
