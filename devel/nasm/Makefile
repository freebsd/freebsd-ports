# New ports collection makefile for:	nasm
# Date created:        7 April 1998
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $FreeBSD$
#

PORTNAME=	nasm
PORTVERSION=	0.98.35
PORTEPOCH=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nasm

MAINTAINER=	murray@FreeBSD.org
COMMENT=	General-purpose multi-platform x86 assembler

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

MAN1=		nasm.1 ndisasm.1

post-install:
	${LN} -sf nasm ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
