# New ports collection makefile for:	cvsnt
# Date created:				21 Jan 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsnt
PORTVERSION=	2.0.14
CATEGORIES=	devel
MASTER_SITES=	http://www.cvsnt.org/archive/ \
		http://homepages.nildram.co.uk/~tmhoyle/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	CVS clone

BROKEN=		"Stomps on libltdl port, and pkg-plist broken"

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-fork
USE_GETOPT_LONG=yes

.if exists(/usr/include/gssapi.h)
PLIST_SUB=	GSERVER=""
.else
PLIST_SUB=	GSERVER="@comment "
.endif

.include <bsd.port.mk>
