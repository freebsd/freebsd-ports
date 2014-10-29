# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virt-manager
PORTVERSION=	0.9.5
PORTREVISION=	7
CATEGORIES=	deskutils net-mgmt
MASTER_SITES=	http://virt-manager.et.redhat.com/download/sources/${PORTNAME}/ \
		LOCAL/jgh/deskutils/${PORTNAME}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	libvirt.so:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.2:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.8:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}virtinst>=0.600.4:${PORTSDIR}/net-mgmt/virtinst \
		${PYTHON_PKGNAMEPREFIX}vte>=0.26.2:${PORTSDIR}/x11-toolkits/py-vte \
		gtk-vnc>=0.3.10:${PORTSDIR}/net/gtk-vnc \
		librsvg2>=2.32.1:${PORTSDIR}/graphics/librsvg2 \
		${PYTHON_PKGNAMEPREFIX}libvirt>=0:${PORTSDIR}/devel/py-libvirt

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

USE_GNOME=	pygnome2
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	virt-manager.schemas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-tui
USES=		gmake python

post-patch:
	@${REINPLACE_CMD} -e 's|itlocaledir = $$(prefix)/$$(DATADIRNAME)/locale|itlocaledir = $$(prefix)/share/locale|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
