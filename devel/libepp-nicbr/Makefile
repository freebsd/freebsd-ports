# New ports collection makefile for:	libepp-nicbr
# Date created:		2006-07-04
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libepp-nicbr
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.registro.br/pub/libepp-nicbr/

MAINTAINER=	jmelo@FreeBSD.org
COMMENT=	Partial Extensible Provisioning Protocol to .br domains

LIB_DEPENDS=	xerces-c:${PORTSDIR}/textproc/xerces-c2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not build
.endif

.include <bsd.port.post.mk>
