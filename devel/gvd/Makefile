# New ports collection makefile for:    gvd
# Date created:         4 Dec 2000
# Whom:                 Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=		gvd
PORTVERSION=		1.2.0
CATEGORIES=		devel
MASTER_SITES=		http://libre.act-europe.fr/gvd/
DISTFILES=		${PORTNAME}-${PORTVERSION}-src.tgz

MAINTAINER=		sam@inf.enst.fr

BUILD_DEPENDS=		adagcc:${PORTSDIR}/lang/gnat \
			tex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=		gtkada.12:${PORTSDIR}/x11-toolkits/gtkada

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CC=adagcc
MAKE_ENV=		CC=adagcc
USE_X_PREFIX=		yes
USE_GMAKE=		yes

.include <bsd.port.mk>
