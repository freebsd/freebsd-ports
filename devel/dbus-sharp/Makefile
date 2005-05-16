# New ports collection makefile for:		dbus-sharp
# Date Created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $Id: Makefile,v 1.8 2005/05/13 06:56:04 tmclau02 Exp $
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-sharp

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono interface to the D-BUS messaging system

LIB_DEPENDS=	dbus-1.1:${PORTSDIR}/devel/dbus
BUILD_DEPENDS=	monodoc:${PORTSDIR}/devel/monodoc
RUN_DEPENDS=	${BUILD_DEPENDS}

MASTERDIR=	${.CURDIR}/../dbus
BUILD_WRKSRC=	${WRKSRC}/mono
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

DBUS_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget
USE_PYTHON=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-mono \
		--disable-python \
		--disable-gcj \
		--disable-gtk \
		--disable-qt \
		--with-system-pid-file=/var/run/dbus.pid \
		--with-system-socket=/var/run/dbus \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/mono/doc/Makefile.in

.include "${MASTERDIR}/Makefile"
