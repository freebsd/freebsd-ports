# New ports collection makefile for:	p5-Test-Manifest
# Date created:				01 Nov 2003
# Whom:	      				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Manifest
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to interact with a t/test_manifest file

PERL_CONFIGURE=	YES

MAN3=		Test::Manifest.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Requires perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
