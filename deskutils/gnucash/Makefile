# ex:ts=8
# Ports collection makefile for:  foo
# Version required:     	  2.1
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	xacc-1.0.17
PKGNAME=	gnucash-1.0.17
CATEGORIES=	misc
MASTER_SITES=	http://www.gnucash.org/xacc/download/

MAINTAINER=     obrien@FreeBSD.org

REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	depend default

post-install:
	@strip ${PREFIX}/bin/xacc.bin
	@${LN} -f ${PREFIX}/bin/xacc ${PREFIX}/bin/gnucash
	@${LN} -f ${PREFIX}/bin/xacc.bin ${PREFIX}/bin/gnucash.bin

.include <bsd.port.mk>
