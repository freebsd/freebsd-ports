# New ports collection makefile for:    sced
# Version required:     0.94
# Date created:         27  Dec 1996
# Whom:                 proff@iq.org
#
# $Id: Makefile,v 1.6 1996/12/06 23:43:32 asami Exp $
#

DISTNAME=       sced-0.94
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.su.oz.au/stephen/sced/src/

CONFIGURE=	true
GNU_CONFIGURE=	true
IS_INTERACTIVE=	true

do-install: all
	${INSTALL_PROGRAM}  $(WRKSRC)/sced $(PREFIX)/bin
	${MKDIR} -p $(PREFIX)/share/doc/sced
	${INSTALL_DATA} $(WRKSRC)/docs/* $(PREFIX)/share/doc/sced
	${MKDIR} -p $(PREFIX)/lib/sced/tutorials
	${INSTALL_DATA} $(WRKSRC)/tutorials/* $(PREFIX)/lib/sced/tutorials
	${INSTALL_DATA} $(WRKSRC)/scenerc $(PREFIX)/lib/sced

.include <bsd.port.mk>
