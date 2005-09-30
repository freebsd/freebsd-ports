# New ports collection makefile for:   mercator
# Date created:        4 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	mercator
PORTVERSION=	0.2.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A procedural terrain library

LIB_DEPENDS=	wfmath-0.3.3:${PORTSDIR}/math/wfmath

USE_GNOME=	pkgconfig
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CXXFLAGS+=	-include wchar.h
CONFIGURE_ARGS+="CXXFLAGS=${CXXFLAGS}"

.include <bsd.port.mk>
