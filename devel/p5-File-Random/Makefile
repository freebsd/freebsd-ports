# New ports collection makefile for:	p5-File-Random
# Date created: 			01 July 2005
# Whom: 				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	File-Random
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Perl module for random selecting of a file

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Want.pm:${PORTSDIR}/devel/p5-Want
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Random.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE= Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
