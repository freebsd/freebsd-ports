# New ports collection makefile for:	libev
# Date created:							18 Dec 2007
# Whom:									vsevolod
#
# $FreeBSD$
#

PORTNAME=	libev
PORTVERSION=	4.04
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/ \
		http://dist.schmorp.de/libev/Attic/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	A full-featured and high-performance event loop library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig

MAN3=		ev.3

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
		${FILESDIR}/libev.pc.in > ${WRKDIR}/libev.pc

post-install:
	@${INSTALL_DATA} ${WRKDIR}/libev.pc ${PKGCONFIGDIR}/

.include <bsd.port.mk>
