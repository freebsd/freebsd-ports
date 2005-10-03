# New ports collection makefile for:   eris
# Date created:        3 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	eris
PORTVERSION=	1.3.7
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge client entity library

LIB_DEPENDS=	Atlas-0.6.0:${PORTSDIR}/devel/atlas-devel \
		skstream-0.3.3:${PORTSDIR}/net/skstream \
		wfmath-0.3.3:${PORTSDIR}/math/wfmath \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack

CXXFLAGS+=	-include wchar.h
CONFIGURE_ARGS+="CXXFLAGS=${CXXFLAGS}"

.include <bsd.port.mk>
