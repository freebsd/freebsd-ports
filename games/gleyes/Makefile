# New ports collection makefile for:	gleyes
# Version required:	0.2
# Date created:		2 December 1998
# Whom:			Malte Lance <malte.lance@gmx.net>
#
# $Id$
#

DISTNAME=	gleyes-0.2
CATEGORIES=	games
MASTER_SITES=	http://puma.inf.ufpr.br/~claudio/gleyes/

MAINTAINER=	malte.lance@gmx.net

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3

MAN1=		gleyes.1
USE_X_PREFIX=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gleyes ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/gleyes.1 ${PREFIX}/man/man1/gleyes.1

.include <bsd.port.mk>
