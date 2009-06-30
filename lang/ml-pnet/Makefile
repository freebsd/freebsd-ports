# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	ml-pnet
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Mono's upper-level libraries

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		treecc:${PORTSDIR}/lang/treecc \
		${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib
RUN_DEPENDS=	${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.mk>
