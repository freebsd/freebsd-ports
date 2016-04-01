# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/ndesk-dbus-glib/Makefile,v 1.2 2008/01/14 22:35:41 mezz Exp $

PORTNAME=	ndesk-dbus-glib
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib main loop integration for Managed D-Bus

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:devel/ndesk-dbus
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:devel/ndesk-dbus

USES=		gmake mono pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS COPYING README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
