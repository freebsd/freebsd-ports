# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	pnetC
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANSI-compatible C library for pnet's cscc compiler

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib
RUN_DEPENDS=	${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib

BROKEN=		does not build
DEPRECATED=	has been broken for 5 months
EXPIRATION_DATE=2010-01-08

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.mk>
