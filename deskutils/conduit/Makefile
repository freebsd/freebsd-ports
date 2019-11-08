# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/deskutils/conduit/Makefile,v 1.7 2008/03/18 14:53:42 ahze Exp $

PORTNAME=	conduit
PORTVERSION=	0.3.17
PORTREVISION=	11
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Synchronization application for GNOME

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/goocanvasmodule.so:graphics/py-goocanvas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:deskutils/py-vobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/goocanvasmodule.so:graphics/py-goocanvas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:deskutils/py-vobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		xdg-open:devel/xdg-utils

USES=		gettext gmake gnome localbase:ldflags pathfix pkgconfig \
		python:2.7 shebangfix
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	intltool pygnome2 gnomeprefix gnomedocutils
CONFIGURE_ARGS=	--disable-nautilus-extension
SHEBANG_FILES=	conduit/conduit.real \
		tools/conduit-client
NO_ARCH=	yes

OPTIONS_DEFINE=	EOG
OPTIONS_DEFAULT=EOG
EOG_DESC=	Build Eye-Of-Gnome Plugin
EOG_BUILD_DEPENDS=	eog:graphics/eog
EOG_RUN_DEPENDS=	eog:graphics/eog
EOG_CONFIGURE_ON=	--enable-eog-plugin

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
		-e 's|/usr/bin/python|${LOCALBASE}/bin/python|' \
		-e 's|/usr/lib/firefox*|${LOCALBASE}/lib/firefox|'

.include <bsd.port.mk>
