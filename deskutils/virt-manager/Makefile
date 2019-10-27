# $FreeBSD$

PORTNAME=	virt-manager
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	deskutils net-mgmt
MASTER_SITES=	https://virt-manager.org/download/sources/${PORTNAME}/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	libvirt.so:devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.2:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.8:textproc/py-libxml2@${PY_FLAVOR} \
		vte3>=0:x11-toolkits/vte3 \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=0:devel/py-ipaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		gtk-vnc>=0.4.4:net/gtk-vnc \
		libvirt-glib>=0.1.9:devel/libvirt-glib \
		libosinfo>=0:devel/libosinfo \
		spice-gtk>=0.26:deskutils/spice-gtk \
		ssh-askpass:security/openssh-askpass

PYDISTUTILS_INSTALLNOSINGLE=	yes
PYDISTUTILS_CONFIGURE_TARGET=	configure
PYDISTUTILS_CONFIGUREARGS=	--prefix=${PREFIX}
USES=		python:3.3+ gettext gnome shebangfix
USE_PYTHON=	noegginfo autoplist distutils noflavors

NO_ARCH=	yes

USE_GNOME=	gtksourceview4 introspection:run intltool librsvg2 pygobject3

INSTALLS_ICONS=	yes

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
