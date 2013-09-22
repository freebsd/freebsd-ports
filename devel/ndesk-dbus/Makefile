# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/ndesk-dbus/Makefile,v 1.2 2008/01/14 22:35:41 mezz Exp $

PORTNAME=	ndesk-dbus
PORTVERSION=	0.6.1a
CATEGORIES=	devel
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A C\# implementation of D-Bus

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

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
