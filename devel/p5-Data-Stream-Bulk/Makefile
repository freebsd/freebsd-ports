# New ports collection makefile for:	Data::Stream::Bulk
# Date created:				2008-11-28
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Stream-Bulk
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	N at a time iteration API

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-DBD-Mock>=0:${PORTSDIR}/databases/p5-DBD-Mock \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Test-TempDir>=0:${PORTSDIR}/devel/p5-Test-TempDir \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN3=		Data::Stream::Bulk.3 \
		Data::Stream::Bulk::Array.3 \
		Data::Stream::Bulk::Callback.3 \
		Data::Stream::Bulk::Cat.3 \
		Data::Stream::Bulk::DBI.3 \
		Data::Stream::Bulk::DBIC.3 \
		Data::Stream::Bulk::DoneFlag.3 \
		Data::Stream::Bulk::Filter.3 \
		Data::Stream::Bulk::Nil.3 \
		Data::Stream::Bulk::Path::Class.3 \
		Data::Stream::Bulk::Util.3

# minor fixes for pod2man
post-patch:
	${PERL} -pi"" -e "s/METHODS/METHODS\n\n=over 4/" ${WRKSRC}/lib/Data/Stream/Bulk/Filter.pm
	${PERL} -pi"" -e "s/<max_rows\)/<max_rows>)/" ${WRKSRC}/lib/Data/Stream/Bulk/DBI.pm

.include <bsd.port.mk>
