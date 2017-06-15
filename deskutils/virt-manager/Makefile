# $FreeBSD$

PORTNAME=	virt-manager
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	deskutils net-mgmt
MASTER_SITES=	http://virt-manager.org/download/sources/${PORTNAME}/ \
		LOCAL/jgh/deskutils/${PORTNAME}/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	libvirt.so:devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.2:devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.8:textproc/py-libxml2 \
		vte3>=0:x11-toolkits/vte3 \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=0:devel/py-ipaddr \
		${PYTHON_PKGNAMEPREFIX}urlgrabber>=0:www/py-urlgrabber \
		${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		gtk-vnc>=0.4.4:net/gtk-vnc \
		libvirt-glib>=0.1.9:devel/libvirt-glib \
		libosinfo>=0:devel/libosinfo \
		spice-gtk>=0.26:deskutils/spice-gtk

PYDISTUTILS_INSTALLNOSINGLE=	yes
PYDISTUTILS_CONFIGURE_TARGET=	configure
PYDISTUTILS_CONFIGUREARGS=	--prefix=${PREFIX}
INSTALLS_ICONS=	yes
USES=		python:2.7 gettext shebangfix
USE_PYTHON=	noegginfo autoplist distutils

NO_ARCH=	yes

USE_GNOME=	introspection:run intltool librsvg2 pygobject3

INSTALLS_ICONS=	yes

python_OLD_CMD=	"/usr/bin/python2 -tt"
SHEBANG_FILES=	virt-manager \
		virt-install \
		virt-clone \
		virt-convert \
		virt-xml

GLIB_SCHEMAS=	org.virt-manager.virt-manager.gschema.xml

#add workaround for two autoplist functions
post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas/
.for file in ${GLIB_SCHEMAS}
	${INSTALL_DATA} ${WRKSRC}/data/${file} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.endfor

.include <bsd.port.mk>
