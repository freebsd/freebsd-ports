# New ports collection makefile for:	nasm
# Version required:    0.95
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id$
#

DISTNAME=	nasm-0.95
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/assemblers

MAINTAINER=	murray@cdrom.com

MAN1=		nasm.1 ndisasm.1

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} nasm ndisasm ${PREFIX}/bin &&\
	${INSTALL_MAN} nasm.1 ndisasm.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
