PORTNAME=	virt-manager
PORTVERSION=	5.1.0
CATEGORIES=	deskutils net-mgmt
MASTER_SITES=	https://releases.pagure.org/${PORTNAME}/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities
WWW=		https://virt-manager.org/

LICENSE=	LGPL3

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.2:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libxml2-python>=2.7.8:textproc/libxml2-python@${PY_FLAVOR} \
		vte3>=0:x11-toolkits/vte3 \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=0:devel/py-ipaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		gtk-vnc>=0.4.4:net/gtk-vnc \
		libvirt-glib>=0.1.9:devel/libvirt-glib \
		libosinfo>=0:devel/libosinfo \
		spice-gtk>=0.26:deskutils/spice-gtk \
		ssh-askpass:security/openssh-askpass

USES=		desktop-file-utils gettext gnome meson tar:xz python
USE_GNOME=	gtksourceview4 introspection:run intltool librsvg2 pygobject3
GLIB_SCHEMAS=	org.virt-manager.virt-manager.gschema.xml

CONFIGURE_ARGS=	-Dtests=disabled

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e "s|'python3'|'${PYTHON_CMD}'|" \
		${WRKSRC}/meson.build
	${REINPLACE_CMD} -e 's|"""#!/usr/bin/env python3|"""#!${PYTHON_CMD}|' \
		${WRKSRC}/scripts/make_bin_wrapper.py

.include <bsd.port.mk>
