# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Search-Xapian10
PORTVERSION=	1.0.23.0
CATEGORIES=	databases perl5
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION:R}/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:S/10$//}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	xapian-core10>=1.0.22:${PORTSDIR}/databases/xapian-core10
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-Search-Xapian-1.[^0]*

USES=		perl5
USE_PERL5=	configure
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

post-patch:
	@${REINPLACE_CMD} -e 's/^if (defined $$builddir/if (0/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
