# New ports collection makefile for:	gfont
# Version required:		1.0.1
# Date created:			Tue Sep  9 11:00:14 MET DST 1997
# Whom:				Ralf S. Engelschall <rse@engelschall.com>
#
# $Id$
#

DISTNAME=	gfont-1.0.1
CATEGORIES=	graphics print www
MASTER_SITES=	http://www.engelschall.com/sw/gfont/distrib/ \
		ftp://ftp.engelschall.com/sw/

MAINTAINER=	rse@engelschall.com

RUN_DEPENDS=	mf:${PORTSDIR}/print/teTeX \
		gftopk:${PORTSDIR}/print/teTeX \
		gsftopk:${PORTSDIR}/print/teTeX

USE_PERL5=	yes
HAS_CONFIGURE=	yes

MAN1=		gfont.1

.include <bsd.port.mk>
