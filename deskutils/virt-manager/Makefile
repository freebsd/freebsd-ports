# New ports collection makefile for: virt-manager
# Date created:    2011-05-28
# Whom:      Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	virt-manager
PORTVERSION=	0.9.0
CATEGORIES=	deskutils net-mgmt
MASTER_SITES=	http://virt-manager.et.redhat.com/download/sources/${PORTNAME}/

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	virt.9:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.2:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.8:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}virtinst>=0.600.0:${PORTSDIR}/net-mgmt/virtinst \
		${PYTHON_PKGNAMEPREFIX}vte>=0.26.2:${PORTSDIR}/x11-toolkits/py-vte \
		gtk-vnc>=0.3.10:${PORTSDIR}/net/gtk-vnc \
		librsvg2>=2.32.1:${PORTSDIR}/graphics/librsvg2

USE_GNOME=	pygtk2 pygnome2 libgnome gnomelibs
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	virt-manager.schemas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-tui
USE_GMAKE=	yes
USE_PYTHON=	yes

MAN1=		virt-manager.1

.include <bsd.port.mk>
