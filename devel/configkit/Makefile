# New ports collection Makefile for:	ConfigKit
# Date created:		2 September 2008
# Whom:			mat
#
# $FreeBSD$
#

PORTNAME=	configkit
PORTVERSION=	0.4.20080902
CATEGORIES=	devel
MASTER_SITES=	http://phk.freebsd.dk/phkrel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=mat
DISTNAME=	ConfigKit.${PORTVERSION:C/0.4.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A somewhat prototypical facility for generating CLI interfaces

BUILD_DEPENDS=	${LOCALBASE}/lib/libphk.a:${PORTSDIR}/devel/libphk

WRKSRC=		${WRKDIR}/ConfigKit

MAKE_ARGS=	BINDIR=${PREFIX}/bin LIBDIR=${PREFIX}/lib INCLUDEDIR=${PREFIX}/include

.include <bsd.port.mk>
