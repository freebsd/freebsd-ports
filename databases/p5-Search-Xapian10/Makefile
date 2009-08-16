# New ports collection makefile for:	databases/p5-Search-Xapian
# Date created:				Feb 22 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Search-Xapian
PORTVERSION=	1.0.13.1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

BUILD_DEPENDS=	xapian-core>=1.0.10:${PORTSDIR}/databases/xapian-core
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CC=		${CXX}

MAN3=	Search::Xapian.3 \
	Search::Xapian::BM25Weight.3 \
	Search::Xapian::BoolWeight.3 \
	Search::Xapian::Database.3 \
	Search::Xapian::Document.3 \
	Search::Xapian::Enquire.3 \
	Search::Xapian::MultiValueSorter.3 \
	Search::Xapian::PositionIterator.3 \
	Search::Xapian::PostingIterator.3 \
	Search::Xapian::QueryParser.3 \
	Search::Xapian::Stem.3 \
	Search::Xapian::TermGenerator.3 \
	Search::Xapian::TermIterator.3 \
	Search::Xapian::TradWeight.3 \
	Search::Xapian::ValueIterator.3 \
	Search::Xapian::Weight.3 \
	Search::Xapian::WritableDatabase.3

post-extract:
	${PERL} -i -pe 's/^if \(defined \$$builddir/if (0/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
