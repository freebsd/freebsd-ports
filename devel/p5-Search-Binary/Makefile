# New ports collection makefile for:	devel/p5-Search-Binary
# Date created:				03 January 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Search-Binary
PORTVERSION=	0.95
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Search
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module that implements a generic binary search algorithm

PERL_CONFIGURE=	yes

MAN3=		Search::Binary.3

pre-patch:
	@${PERL} -pi -e 's|Seach|Search|' ${WRKSRC}/Binary.pm

.include <bsd.port.mk>
