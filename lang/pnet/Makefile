# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnet
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "meta-port" for DotGNU Portable.NET

BUILD_DEPENDS=	treecc:${PORTSDIR}/lang/treecc
RUN_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		csunit:${PORTSDIR}/lang/pnetlib \
		sqlsharp-pnet:${PORTSDIR}/lang/ml-pnet

DEPRECATED=	Alpha-quality abandonware - Decommissioned Dec 2012 - Use mono
EXPIRATION_DATE=2014-05-01

NO_BUILD=	yes

do-install:	# empty

NO_STAGE=	yes
.include "../pnet/Makefile.pnet"
.include <bsd.port.mk>
