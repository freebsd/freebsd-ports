# ex:ts=8
# Ports collection makefile for:  foo
# Version required:     	  2.1
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.4 1998/08/12 19:00:46 obrien Exp $
#

DISTNAME=	xacc-1.0.18
PKGNAME=	gnucash-1.0.18
CATEGORIES=	deskutils
MASTER_SITES=	http://www.gnucash.org/xacc/download/  \
		ftp://ftp.gnucash.org/pub/xacc/

MAINTAINER=     obrien@FreeBSD.org

REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	depend default

pre-build:
	@${LN} -sf ${WRKSRC}/lib/Xbae-4.6.2-linas/src ${WRKSRC}/lib/Xbae-4.6.2-linas/Xbae

post-install:
	@strip ${PREFIX}/bin/xacc.bin
	@${LN} -f ${PREFIX}/bin/xacc ${PREFIX}/bin/gnucash
	@${LN} -f ${PREFIX}/bin/xacc.bin ${PREFIX}/bin/gnucash.bin

.include <bsd.port.mk>
