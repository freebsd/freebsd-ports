# New ports collection makefile for:	p5-Include
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Include
PORTVERSION=	1.02a
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 package which allows use of macros defined in 'C' header files

PERL_CONFIGURE=	YES

MAN3=		Include.3

post-build:
	@${CP} ${WRKSRC}/Include.pm ${WRKSRC}/blib/lib
	@${MKDIR} ${WRKSRC}/blib/man3
	@pod2man ${WRKSRC}/Include.pm > ${WRKSRC}/blib/man3/Include.3

.include <bsd.port.mk>
