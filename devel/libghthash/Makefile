# ex:ts=8
# Ports collection makefile for:	libghthash
# Date created:			Jul 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libghthash
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ipd.bth.se/ska/sim_home/filer/

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	Generic Hash Table

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--datarootdir=${PREFIX}
USE_LDCONFIG=	yes

PLIST_FILES=	include/ght_hash_table.h \
		lib/libghthash.a  lib/libghthash.la \
		lib/libghthash.so lib/libghthash.so.2

MAN3=	ght_create.3 \
	ght_finalize.3 \
	ght_first.3 \
	ght_first_keysize.3 \
	ght_get.3 \
	ght_insert.3 \
	ght_next.3 \
	ght_next_keysize.3 \
	ght_remove.3

.include <bsd.port.mk>
