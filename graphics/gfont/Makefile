# New ports collection makefile for:	gfont
# Version required:		1.0.2
# Date created:			09-Sep-1997
# Whom:				Ralf S. Engelschall <rse@engelschall.com>
#
# $Id: Makefile,v 1.5 1998/11/15 20:47:32 jseger Exp $
#

DISTNAME=	gfont-1.0.2
CATEGORIES=	graphics print www
MASTER_SITES=	http://www.engelschall.com/sw/gfont/distrib/ \
		ftp://ftp.engelschall.com/sw/gfont/ \
		ftp://ftp.hyperreal.org/software/engelschall/gfont/

MAINTAINER=	rse@engelschall.com

RUN_DEPENDS=	mf:${PORTSDIR}/print/teTeX \
		gftopk:${PORTSDIR}/print/teTeX \
		gsftopk:${PORTSDIR}/print/teTeX

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300003
BROKEN=		perl5
.endif

USE_PERL5=	yes
HAS_CONFIGURE=	yes

MAN1=		gfont.1

.include <bsd.port.mk>
