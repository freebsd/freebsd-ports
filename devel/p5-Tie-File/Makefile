# New ports collection makefile for:	p5-Tie-File
# Date created:				17 June 2003
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-File
PORTVERSION=	0.96
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Access the lines of a disk file via a Perl array

PERL_CONFIGURE=	yes

MAN3=		Tie::File.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} > 500703
IGNORE=		"This port is for perl 5.7.2 and under only."
.endif

.include <bsd.port.post.mk>
