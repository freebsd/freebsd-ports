# New ports collection makefile for:	databases/p5-DBIx-Perlish
# Date created:				22 February 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Perlish
PORTVERSION=	0.26
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A perlish interface to SQL databases

BUILD_DEPENDS=	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-PadWalker>0:${PORTSDIR}/devel/p5-PadWalker
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Perlish.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500802
IGNORE=		requires perl 5.8.2 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
