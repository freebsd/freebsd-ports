# New ports collection makefile for:	IO::NestedCapture
# Date created:				21 Dec 2005
# Whom:					tobez@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	IO-NestedCapture
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for performing nested STD\* handle captures

PERL_MODBUILD=	yes

MAN3=		IO::NestedCapture.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
