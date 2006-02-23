# ex:ts=8
# Ports collection makefile for:	libghthash
# Date created:			Jul 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libghthash
PORTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ipd.bth.se/ska/sim_home/filer/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Generic Hash Table

USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

PLIST_FILES=	include/ght_hash_table.h \
		lib/libghthash.a  lib/libghthash.la \
		lib/libghthash.so lib/libghthash.so.5

.include <bsd.port.mk>
