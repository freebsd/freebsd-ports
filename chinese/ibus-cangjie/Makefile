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
BUILD_DEPENDS=	${PREFIX}/lib/python3.6/site-packages/cangjie/_core.so:chinese/pycangjie
RUN_DEPENDS=	${PREFIX}/lib/python3.6/site-packages/cangjie/_core.so:chinese/pycangjie \
		${PYTHON_SITELIBDIR}/pycanberra/__init__.py:devel/pycanberra@py36

USES=		autoreconf gmake libtool pkgconfig python:3.6

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	gettext

INSTALLS_ICONS=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		PYTHON=${PYTHON_CMD}

USE_GNOME=		introspection:run py3gobject3 intltool

USE_GITHUB=		yes
GH_ACCOUNT=		Cangjians
GH_PROJECT=		ibus-cangjie

# ugly kludge fix for this:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224486
# We know python3 will be installed so we work around this check
do-configure:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|([3.2.3])|([2.7])|g' ${WRKSRC}/configure.ac && \
	      autopoint --force && \
	      intltoolize --force --copy --automake && \
	      aclocal -I m4 && \
	      autoheader && \
	      automake --add-missing --copy && \
	      autoconf && \
	     ./configure ${CONFIGURE_ENV})

.include <bsd.port.mk>
