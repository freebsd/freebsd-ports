# New ports collection makefile for:	bcc
# Date created:		26 March 1995
# Whom:			joerg
#
# $FreeBSD$
#

PORTNAME=	bcc
PORTVERSION=	1995.03.12
CATEGORIES=	devel lang
DISTNAME=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Bruce's C compiler (with as and ld); can do 16-bit code

CONFLICTS=	bin86-*
MAN1=		as86.1 bcc.1 bcc-cc1.1 ld86.1
.if !defined(NOMANCOMPRESS)
MANCOMPRESSED=	yes
.endif

.include <bsd.port.mk>
