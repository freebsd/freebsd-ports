# New ports collection makefile for:	libepp-nicbr
# Date created:		2006-07-04
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libepp-nicbr
PORTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.registro.br/pub/libepp-nicbr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Partial Extensible Provisioning Protocol to .br domains

LIB_DEPENDS=	xerces-c:${PORTSDIR}/textproc/xerces-c2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xerces-c=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}

DATADIR=	share/${PORTNAME:S/-/_/}

PLIST_SUB=	VER="${PORTVERSION}"

.include <bsd.port.mk>
