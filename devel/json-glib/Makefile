# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	json-glib
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	GIR DOCS
OPTIONS_DEFAULT=GIR
OPTIONS_SUB=	yes

GIR_DESC=	Build introspection data
GIR_USE=	gnome=introspection
GIR_MESON_TRUE=	introspection

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/libexec/installed-tests
	@${RM} -r ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
