# New ports collection makefile for:	DOC++
# Date created:		20 Dec 1998
# Whom:			Ruslan@Shevchenko.Kiev.UA
# Version required:	3.3.13
#
# $Id: Makefile,v 1.2 1999/05/03 01:52:27 steve Exp $
#

DISTNAME=	doc++-3.3.13
CATEGORIES=	devel
MASTER_SITES=	http://www.imaginator.com/doc++/

MAINTAINER=	Ruslan@Shevchenko.Kiev.UA

RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX \
		gs:${PORTSDIR}/print/ghostscript5 \
		anytopnm:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
