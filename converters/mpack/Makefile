# New ports collection makefile for:    mpack
# Date created:         1 May 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	mpack
PORTVERSION=	1.5
PORTREVISION=   3
CATEGORIES=	converters mail news
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/mpack/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ache@FreeBSD.org
COMMENT=	External MIME packer/unpacker

WRKSRC=		${WRKDIR}/mpack
MAKEFLAGS=	-f
MAKE_ENV+=	DESTDIR=${PREFIX}
MAN1=		mpack.1 munpack.1

.include <bsd.port.mk>
