# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	fs-uae-launcher
PORTVERSION=	2.8.4
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/fs-uae/stable/${PORTVERSION}/

MAINTAINER=	ndowens@yahoo.com
COMMENT=	GUI launcher for the FS-UAE Amiga emulator

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		gettext gmake gnome pathfix pyqt:5 python:3.4+

USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	core sip gui widgets opengl

INSTALLS_ICONS=	yes
MAKE_ARGS+=	DESTDIR=${STAGEDIR} prefix=${PREFIX} PYTHON=${PYTHON_CMD}

PYDISTUTILS_INSTALLARGS+=	--install-lib=${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
