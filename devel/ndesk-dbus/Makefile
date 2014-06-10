# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/ndesk-dbus/Makefile,v 1.2 2008/01/14 22:35:41 mezz Exp $

PORTNAME=	ndesk-dbus
PORTVERSION=	0.6.1a
CATEGORIES=	devel
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C\# implementation of D-Bus

OPTIONS_DEFINE=	DOCS
USES=	gmake mono pathfix pkgconfig
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
