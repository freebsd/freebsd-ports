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

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus

USE_GMAKE=	yes
USES=	pathfix pkgconfig
GNU_CONFIGURE=	yes
NO_STAGE=	yes

DOCS=		AUTHORS COPYING README

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
