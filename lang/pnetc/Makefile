# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	pnetC
PORTVERSION=	${PNET_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}

MAINTAINER=	ahze@ahze.net
COMMENT=	ANSI-compatible C library for pnet's cscc compiler

BUILD_DEPENDS=	${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib
RUN_DEPENDS=	${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib

USE_LIBTOOL=	yes
USE_GMAKE=	yes
STRIP=		# Nothing to be stripped.

.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.mk>
