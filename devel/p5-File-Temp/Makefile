# New ports collection makefile for:	p5-File-Temp
# Date created:		13 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	File-Temp
PORTVERSION=	0.18
PORTREVISION=	0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Perl5 module to generate temporary files or directories safely

PERL_CONFIGURE=	yes

MAN3=		File::Temp.3

.include <bsd.port.pre.mk>

# requires Carp::Heavy since File-Temp-0.17
.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
