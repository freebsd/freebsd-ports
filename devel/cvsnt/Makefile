# New ports collection makefile for:	cvsnt
# Date created:				21 Jan 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsnt
PORTVERSION=	2.0.34
CATEGORIES=	devel
MASTER_SITES=	http://www.cvsnt.org/archive/ \
		http://homepages.nildram.co.uk/~tmhoyle/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	CVS clone

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl

USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--enable-fork
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETOPT_LONG=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		cvs.1
MAN5=		cvs.5

.if exists(/usr/include/gssapi.h)
PLIST_SUB=	GSERVER=""
.else
PLIST_SUB=	GSERVER="@comment "
.endif

.include <bsd.port.mk>
