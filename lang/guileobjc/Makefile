# New ports collection makefile for:   guileobjc
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	guileobjc
PORTVERSION=	0.3.8
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gyve/fullkit/gyve-0.1.2.4/

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libobjects.a:${PORTSDIR}/lang/libobjects
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile

BROKEN=		Doesn\'t work with the latest guile.

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
