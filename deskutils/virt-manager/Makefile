# $FreeBSD$

PORTNAME=	virt-manager
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	deskutils net-mgmt
MASTER_SITES=	http://virt-manager.org/download/sources/${PORTNAME}/ \
		LOCAL/jgh/deskutils/${PORTNAME}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	libvirt.so:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.2:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.8:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}vte>=0.26.2:${PORTSDIR}/x11-toolkits/py-vte \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=0:${PORTSDIR}/devel/py-ipaddr \
		${PYTHON_PKGNAMEPREFIX}urlgrabber>=0:${PORTSDIR}/www/py-urlgrabber \
		${PYTHON_PKGNAMEPREFIX}libvirt>=0:${PORTSDIR}/devel/py-libvirt \
		gtk-vnc>=0.4.4:${PORTSDIR}/net/gtk-vnc \
		libvirt-glib>=0.1.9:${PORTSDIR}/devel/libvirt-glib \
		libosinfo>=0:${PORTSDIR}/devel/libosinfo \
		${PYTHON_PKGNAMEPREFIX}spice-gtk>=0.26:${PORTSDIR}/deskutils/py-spice-gtk

PYDISTUTILS_INSTALLNOSINGLE=	yes
PYDISTUTILS_CONFIGURE_TARGET=	configure
PYDISTUTILS_CONFIGUREARGS=	--prefix=${PREFIX}
USES=	python:2.7 gettext shebangfix
USE_PYTHON=	distutils autoplist

USE_GNOME=	introspection:run intltool librsvg2 pygobject3

INSTALLS_ICONS=	yes

SHEBANG_FILES=	virt-manager \
		virt-install \
		virt-clone \
		virt-convert

GLIB_SCHEMAS=	org.virt-manager.virt-manager.gschema.xml

.include <bsd.port.mk>
