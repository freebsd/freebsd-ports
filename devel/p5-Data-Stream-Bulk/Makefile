# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Stream-Bulk
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	N at a time iteration API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

MAN3=		Data::Stream::Bulk.3 \
		Data::Stream::Bulk::Array.3 \
		Data::Stream::Bulk::Callback.3 \
		Data::Stream::Bulk::Cat.3 \
		Data::Stream::Bulk::Chunked.3 \
		Data::Stream::Bulk::DBI.3 \
		Data::Stream::Bulk::DBIC.3 \
		Data::Stream::Bulk::DoneFlag.3 \
		Data::Stream::Bulk::FileHandle.3 \
		Data::Stream::Bulk::Filter.3 \
		Data::Stream::Bulk::Nil.3 \
		Data::Stream::Bulk::Path::Class.3 \
		Data::Stream::Bulk::Util.3

.include <bsd.port.mk>
