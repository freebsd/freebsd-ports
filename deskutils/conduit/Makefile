# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/deskutils/conduit/Makefile,v 1.7 2008/03/18 14:53:42 ahze Exp $

PORTNAME=	conduit
PORTVERSION=	0.3.17
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Synchronization application for GNOME

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/goocanvasmodule.so:${PORTSDIR}/graphics/py-goocanvas \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:${PORTSDIR}/deskutils/py-vobject \
		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/goocanvasmodule.so:${PORTSDIR}/graphics/py-goocanvas \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:${PORTSDIR}/deskutils/py-vobject \
		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		xdg-open:${PORTSDIR}/devel/xdg-utils

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	pygnome2 gnomeprefix

OPTIONS_DEFINE=	NAUTILUS EOG
OPTIONS_DEFAULT=NAUTILUS EOG
NAUTILUS_DESC=	Build Nautilus Plugin
EOG_DESC=	Build Eye-Of-Gnome Plugin

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus2
CONFIGURE_ARGS+=	--enable-nautilus-extension
.endif

.if ${PORT_OPTIONS:MEOG}
BUILD_DEPENDS+=	eog:${PORTSDIR}/graphics/eog
RUN_DEPENDS+=	eog:${PORTSDIR}/graphics/eog
CONFIGURE_ARGS+=	--enable-eog-plugin
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/data/Makefile.in
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
		-e 's|/usr/bin/python|${LOCALBASE}/bin/python|' \
		-e 's|/usr/lib/firefox*|${LOCALBASE}/lib/firefox|'

.include <bsd.port.mk>
