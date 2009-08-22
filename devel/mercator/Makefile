# New ports collection makefile for:   mercator
# Date created:        4 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	mercator
PORTVERSION=	0.2.7
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/Mercator%20%28terrain%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A procedural terrain library

LIB_DEPENDS=	wfmath-0.3.4:${PORTSDIR}/math/wfmath

USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CXXFLAGS+=	-include wchar.h
CONFIGURE_ARGS+="CXXFLAGS=${CXXFLAGS}"

.include <bsd.port.mk>
