# New ports collection makefile for:		dbus-sharp
# Date Created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.18 2006/01/02 20:54:03 tmclau02 Exp $
#

PORTREVISION=	12
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-sharp

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono interface to the D-BUS messaging system

LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus
BUILD_DEPENDS=	monodoc:${PORTSDIR}/devel/mono-tools
RUN_DEPENDS=	monodoc:${PORTSDIR}/devel/mono-tools

MASTERDIR=	${.CURDIR}/../dbus
BUILD_WRKSRC=	${WRKSRC}/mono
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

DBUS_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget
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

# Disable those, since it doesn't install docs yet.
#post-patch:
#	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
#		${WRKSRC}/mono/doc/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${MASTERDIR}/Makefile"
