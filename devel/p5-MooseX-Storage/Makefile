# New ports collection makefile for:	devel/p5-MooseX-Storage
# Date created:				2008/09/06
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	MooseX-Storage
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An serialization framework for Moose classes

BUILD_DEPENDS=	p5-Moose>=0.39:${PORTSDIR}/devel/p5-Moose \
		p5-JSON-Any>=1.15:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Test-JSON>=0.06:${PORTSDIR}/devel/p5-Test-JSON \
		p5-Best>=0.1:${PORTSDIR}/devel/p5-Best \
		p5-Test-YAML-Valid>=0:${PORTSDIR}/devel/p5-Test-YAML-Valid \
		p5-Test-Simple>=0.42:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-TempDir>=0.02:${PORTSDIR}/devel/p5-Test-TempDir
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		MooseX::Storage.3 \
		MooseX::Storage::Base::WithChecksum.3 \
		MooseX::Storage::Basic.3 \
		MooseX::Storage::Deferred.3 \
		MooseX::Storage::Engine.3 \
		MooseX::Storage::Engine::IO::AtomicFile.3 \
		MooseX::Storage::Engine::IO::File.3 \
		MooseX::Storage::Engine::Trait::DisableCycleDetection.3 \
		MooseX::Storage::Engine::Trait::OnlyWhenBuilt.3 \
		MooseX::Storage::Format::JSON.3 \
		MooseX::Storage::Format::Storable.3 \
		MooseX::Storage::Format::YAML.3 \
		MooseX::Storage::IO::AtomicFile.3 \
		MooseX::Storage::IO::File.3 \
		MooseX::Storage::IO::StorableFile.3 \
		MooseX::Storage::Meta::Attribute::DoNotSerialize.3 \
		MooseX::Storage::Meta::Attribute::Trait::DoNotSerialize.3 \
		MooseX::Storage::Traits::DisableCycleDetection.3 \
		MooseX::Storage::Traits::OnlyWhenBuilt.3 \
		MooseX::Storage::Util.3

.include <bsd.port.mk>
