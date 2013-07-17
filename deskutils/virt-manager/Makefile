# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virt-manager
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	deskutils net-mgmt
MASTER_SITES=	http://virt-manager.et.redhat.com/download/sources/${PORTNAME}/ \
		LOCAL/jgh/deskutils/${PORTNAME}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	virt.1001:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.2:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.8:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}virtinst>=0.600.4:${PORTSDIR}/net-mgmt/virtinst \
		${PYTHON_PKGNAMEPREFIX}vte>=0.26.2:${PORTSDIR}/x11-toolkits/py-vte \
		gtk-vnc>=0.3.10:${PORTSDIR}/net/gtk-vnc \
		librsvg2>=2.32.1:${PORTSDIR}/graphics/librsvg2

FETCH_ARGS?=	-Fpr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

USE_GNOME=	pygnome2
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	virt-manager.schemas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-tui
USES=		gmake
USE_PYTHON=	yes

MAN1=		virt-manager.1

post-patch-script:
	@${REINPLACE_CMD} -e 's|itlocaledir = $$(prefix)/$$(DATADIRNAME)/locale|itlocaledir = $$(prefix)/share/locale|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
