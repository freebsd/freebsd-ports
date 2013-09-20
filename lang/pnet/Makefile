# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnet
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	The "meta-port" for DotGNU Portable.NET

BUILD_DEPENDS=	treecc:${PORTSDIR}/lang/treecc
RUN_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		csunit:${PORTSDIR}/lang/pnetlib \
		sqlsharp-pnet:${PORTSDIR}/lang/ml-pnet

NO_BUILD=	yes

do-install:	# empty

NO_STAGE=	yes
.include "../pnet/Makefile.pnet"
.include <bsd.port.mk>
