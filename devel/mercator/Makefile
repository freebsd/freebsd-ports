# New ports collection makefile for:   mercator
# Date created:        4 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	mercator
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.worldforge.org/pub/worldforge/libs/mercator/ \
		http://purple.worldforge.org/downloads/libs/mercator/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	jannisan@t-online.de
COMMENT=	A procedural terrain library

LIB_DEPENDS=	wfmath-0.3.3:${PORTSDIR}/math/wfmath

USE_GNOME=	pkgconfig
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CXXFLAGS+=	-include wchar.h
CONFIGURE_ARGS+="CXXFLAGS=${CXXFLAGS}"

.include <bsd.port.mk>
