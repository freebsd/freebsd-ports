# New ports collection makefile for:	nasm
# Version required:    0.98
# Date created:        7 April 1998
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $FreeBSD$
#

DISTNAME=	nasm-0.98
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/assemblers

MAINTAINER=	murray@cdrom.com

GNU_CONFIGURE=	yes

MAN1=		nasm.1 ndisasm.1

post-install:
	${LN} -sf nasm ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
