# New ports collection makefile for:	p5-Convert-UU
# Version required:			0.20
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.12 1998/02/18 18:16:01 vanilla Exp $
#

DISTNAME=	Convert-UU-0.20
PKGNAME=	p5-Convert-UU-0.20
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert

MAINTAINER=	jfitz@FreeBSD.ORG

BROKEN=		perl upgrade

USE_PERL5=	YES

MAN1=		puuencode.1 puudecode.1
MAN3=		Convert::UU.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
