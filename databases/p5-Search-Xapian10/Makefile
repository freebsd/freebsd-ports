# New ports collection makefile for:	databases/p5-Search-Xapian
# Date created:				Feb 22 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Search-Xapian
PORTVERSION=	0.9.2.4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Search
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

BUILD_DEPENDS=	xapian-core>=0:${PORTSDIR}/databases/xapian-core
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CC=		${CXX}

MAN3=	Search::Xapian.3 \
	Search::Xapian::BM25Weight.3 \
	Search::Xapian::BoolWeight.3 \
	Search::Xapian::Database.3 \
	Search::Xapian::Document.3 \
	Search::Xapian::Enquire.3 \
	Search::Xapian::PositionIterator.3 \
	Search::Xapian::PostingIterator.3 \
	Search::Xapian::QueryParser.3 \
	Search::Xapian::Stem.3 \
	Search::Xapian::TermIterator.3 \
	Search::Xapian::Weight.3 \
	Search::Xapian::WritableDatabase.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6. Install lang/perl5 or perl5.8 and try again
.endif
.include <bsd.port.post.mk>
