# New ports collection makefile for:   py-dbus
# Date Created:			25 July 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	devel gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the D-BUS messaging system

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

MASTERDIR=	${.CURDIR}/../dbus
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

NOT_FOR_ARCHS=	ia64

DBUS_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget
USE_PYTHON=	yes
CONFIGURE_ARGS=	--enable-python \
		--disable-gcj \
		--disable-mono \
		--disable-mono-docs \
		--disable-gtk \
		--disable-qt3 \
		--localstatedir=/var \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/dbus.pipe \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
