# New ports collection makefile for:		dbus-sharp
# Date Created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.18 2006/01/02 20:54:03 tmclau02 Exp $
#

PORTNAME=	dbus-sharp
PORTVERSION=	0.62
PORTREVISION=	17
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/
DISTNAME=	dbus-${PORTVERSION}

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono interface to the D-BUS messaging system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus
BUILD_DEPENDS=	monodoc:${PORTSDIR}/devel/mono-tools
RUN_DEPENDS=	monodoc:${PORTSDIR}/devel/mono-tools

BUILD_WRKSRC=	${WRKSRC}/mono
INSTALL_WRKSRC=	${BUILD_WRKSRC}

USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--enable-mono \
		--disable-python \
		--disable-gcj \
		--disable-gtk \
		--disable-qt \
		--with-test-socket-dir=${WRKDIR} \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/system_bus_socket \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

# Disable those, since it doesn't install docs yet.
#post-patch:
#	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
#		${WRKSRC}/mono/doc/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
