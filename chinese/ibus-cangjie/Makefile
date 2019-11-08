# Created by: blubee <hello@blubee.me>
# $FreeBSD$

PORTNAME=		ibus-cangjie
PORTVERSION=		2.4
DISTVERSIONPREFIX=	v
CATEGORIES=		chinese

MAINTAINER=	hello@blubee.me
COMMENT=	IBus engine for users of the Cangjie and Quick

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libibus-1.0.so:textproc/ibus
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/cangjie/_core.so:chinese/pycangjie \
		${PYTHON_SITELIBDIR}/pycanberra/pycanberra.py:devel/pycanberra@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cangjie/_core.so:chinese/pycangjie \
		${PYTHON_SITELIBDIR}/pycanberra/pycanberra.py:devel/pycanberra@${PY_FLAVOR}

USES=		autoreconf gmake gnome libtool pkgconfig python:3.4+
USE_GNOME=	introspection:run pygobject3 intltool
GLIB_SCHEMAS=	org.cangjians.ibus.cangjie.gschema.xml \
		org.cangjians.ibus.quick.gschema.xml

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	gettext

INSTALLS_ICONS=		yes
GNU_CONFIGURE=		yes

USE_GITHUB=		yes
GH_ACCOUNT=		Cangjians
GH_PROJECT=		ibus-cangjie

.include <bsd.port.mk>
