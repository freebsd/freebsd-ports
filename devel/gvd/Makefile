# New ports collection makefile for:    gvd
# Date created:         4 Dec 2000
# Whom:                 Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=		gvd
PORTVERSION=		1.0.1
CATEGORIES=		devel
MASTER_SITES=		http://libre.act-europe.fr/gvd/

MAINTAINER=		sam@inf.enst.fr

BUILD_DEPENDS=		adagcc:${PORTSDIR}/lang/gnat
LIB_DEPENDS=		gtkada-1.2.10:${PORTSDIR}/x11-toolkits/gtkada

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CC=adagcc
MAKE_ENV=		CC=adagcc
USE_X_PREFIX=		yes
USE_GMAKE=		yes

post-extract:
	${CP} ${FILESDIR}/freebsd.h ${WRKSRC}/gnat/system/

.include <bsd.port.mk>
