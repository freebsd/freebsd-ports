# New ports collection makefile for:   eris
# Date created:        3 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	eris
PORTVERSION=	1.2.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	jannisan@t-online.de
COMMENT=	WorldForge client entity library

LIB_DEPENDS=	Atlas-0.5.2:${PORTSDIR}/devel/atlas \
		skstream-0.3.3:${PORTSDIR}/net/skstream \
		wfmath-0.3.3:${PORTSDIR}/math/wfmath \
		sigc-1.2:${PORTSDIR}/devel/libsigc++12

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CXXFLAGS+=	-include wchar.h
CONFIGURE_ARGS+="CXXFLAGS=${CXXFLAGS}"

.include <bsd.port.mk>
