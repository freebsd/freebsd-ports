# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	pnetlib
PORTVERSION=	${PNET_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}

MAINTAINER=	ahze@ahze.net
COMMENT=	C\# system library for pnet

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		treecc:${PORTSDIR}/lang/treecc

USE_LIBTOOL=	yes
USE_GMAKE=	yes
STRIP=		# Nothing to be stripped.

.include <bsd.port.pre.mk>
post-install:
	${STRIP_CMD} ${PREFIX}/lib/cscc/lib/libXsharpSupport.so.0
	${STRIP_CMD} ${PREFIX}/lib/cscc/lib/libXsharpSupport.a

.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.post.mk>
