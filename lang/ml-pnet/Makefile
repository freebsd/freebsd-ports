# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	ml-pnet
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mono's upper-level libraries

DEPRECATED=	Alpha-quality abandonware - Decommissioned Dec 2012 - Use mono
EXPIRATION_DATE=2014-05-01

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		treecc:${PORTSDIR}/lang/treecc \
		${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib
RUN_DEPENDS=	${LOCALBASE}/lib/cscc/lib/libXsharpSupport.so.0:${PORTSDIR}/lang/pnetlib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_STAGE=	yes
.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.mk>
