# New ports collection makefile for:   py-dbus
# Date Created:			25 July 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	devel gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the D-BUS messaging system

LIB_DEPENDS=	dbus-1.0:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

MASTERDIR=	${.CURDIR}/../dbus
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

DBUS_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget
USE_PYTHON=	yes
CONFIGURE_ARGS=	--enable-python \
		--disable-gcj \
		--disable-mono \
		--disable-gtk \
		--with-system-pid-file=/var/run/dbus.pid \
		--with-system-socket=/var/run/dbus \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
