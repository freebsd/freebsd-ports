# New ports collection makefile for:	gleyes
# Version required:	0.2
# Date created:		2 December 1998
# Whom:			Malte Lance <malte.lance@gmx.net>
#
# $Id: Makefile,v 1.1.1.1 1998/12/17 14:34:50 flathill Exp $
#

DISTNAME=	gleyes-0.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.kddlabs.co.jp/.1/X11/acontrib/gleyes/ \
		ftp://ftp.riken.go.jp/pub/X11/acontrib/gleyes/ \
		ftp://ftp.cit.nepean.uws.edu.au/unix/X/graphics/
# initial distribution location was http://puma.inf.ufpr.br/~claudio/gleyes/
# which is unresponsive since about 21.12.1998

MAINTAINER=	malte.lance@gmx.net

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3

MAN1=		gleyes.1
USE_X_PREFIX=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gleyes ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/gleyes.1 ${PREFIX}/man/man1/gleyes.1

.include <bsd.port.mk>
