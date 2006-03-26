# New ports collection makefile for:    mpack
# Date created:         1 May 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	mpack
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	converters mail news
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/mpack/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	External MIME packer/unpacker

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes

MAN1=		mpack.1 munpack.1

PLIST_FILES=	bin/mpack bin/munpack

.include <bsd.port.mk>
