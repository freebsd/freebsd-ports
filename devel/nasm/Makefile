# New ports collection makefile for:	nasm
# Version required:    0.96
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id: Makefile,v 1.2 1997/10/27 00:53:14 chuckr Exp $
#

DISTNAME=	nasm-0.96
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/assemblers

MAINTAINER=	murray@cdrom.com

GNU_CONFIGURE=	yes

MAN1=		nasm.1 ndisasm.1

#do-install:
#	cd ${WRKSRC} && \
#	${INSTALL_PROGRAM} nasm ndisasm ${PREFIX}/bin &&\
#	${INSTALL_MAN} nasm.1 ndisasm.1 ${PREFIX}/man/man1
#	$(MKDIR) -p $(PREFIX)/share/nasm
#	${INSTALL_MAN} $(WRKSRC)/*.doc $(PREFIX)/share/nasm

.include <bsd.port.mk>
