# New ports collection makefile for:	DOC++
# Date created:		20 Dec 1998
# Whom:			Ruslan@Shevchenko.Kiev.UA
# Version required:	3.3.15
#
# $FreeBSD$
#

DISTNAME=	doc++-3.3.15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.imaginator.com/doc++/
MASTER_SITE_SUBDIR=	apps/doctools

MAINTAINER=	Ruslan@Shevchenko.Kiev.UA

RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX \
		gs:${PORTSDIR}/print/ghostscript5 \
		anytopnm:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
