# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Search-Xapian
PORTVERSION=	1.2.15.0
CATEGORIES=	databases perl5
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION:R}/ \
		LOCAL/sunpoet \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	xapian:${PORTSDIR}/databases/xapian-core
TEST_DEPENDS=	p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PORTSCOUT=	limitw:1,even

CC=		${CXX}
CONFIGURE_ARGS=	XAPIAN_CONFIG=${LOCALBASE}/bin/xapian-config
USE_PERL5=	configure
USES=		perl5

MAN3=		Search::Xapian.3 \
		Search::Xapian::AssertionError.3 \
		Search::Xapian::BM25Weight.3 \
		Search::Xapian::BoolWeight.3 \
		Search::Xapian::Database.3 \
		Search::Xapian::DatabaseCorruptError.3 \
		Search::Xapian::DatabaseCreateError.3 \
		Search::Xapian::DatabaseError.3 \
		Search::Xapian::DatabaseLockError.3 \
		Search::Xapian::DatabaseModifiedError.3 \
		Search::Xapian::DatabaseOpeningError.3 \
		Search::Xapian::DatabaseVersionError.3 \
		Search::Xapian::DocNotFoundError.3 \
		Search::Xapian::Document.3 \
		Search::Xapian::Enquire.3 \
		Search::Xapian::Error.3 \
		Search::Xapian::FeatureUnavailableError.3 \
		Search::Xapian::InternalError.3 \
		Search::Xapian::InvalidArgumentError.3 \
		Search::Xapian::InvalidOperationError.3 \
		Search::Xapian::LogicError.3 \
		Search::Xapian::MultiValueSorter.3 \
		Search::Xapian::NetworkError.3 \
		Search::Xapian::NetworkTimeoutError.3 \
		Search::Xapian::PositionIterator.3 \
		Search::Xapian::PostingIterator.3 \
		Search::Xapian::QueryParser.3 \
		Search::Xapian::QueryParserError.3 \
		Search::Xapian::RangeError.3 \
		Search::Xapian::RuntimeError.3 \
		Search::Xapian::SerialisationError.3 \
		Search::Xapian::Stem.3 \
		Search::Xapian::TermGenerator.3 \
		Search::Xapian::TermIterator.3 \
		Search::Xapian::TradWeight.3 \
		Search::Xapian::UnimplementedError.3 \
		Search::Xapian::ValueIterator.3 \
		Search::Xapian::Weight.3 \
		Search::Xapian::WritableDatabase.3

post-patch:
	@${REINPLACE_CMD} -e 's|^if (defined $$builddir) {|if (0) {|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
