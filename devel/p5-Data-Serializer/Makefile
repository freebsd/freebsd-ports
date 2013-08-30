# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Data-Serializer
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Modules that serialize data structures

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Data::Serializer.3 Data::Serializer::Bencode.3 \
		Data::Serializer::Config::General.3 \
		Data::Serializer::Convert::Bencode.3 \
		Data::Serializer::Convert::Bencode_XS.3 \
		Data::Serializer::Cookbook.3 Data::Serializer::Data::Denter.3 \
		Data::Serializer::Data::Dumper.3 Data::Serializer::Data::Taxi.3 \
		Data::Serializer::FreezeThaw.3 Data::Serializer::JSON.3 \
		Data::Serializer::JSON::Syck.3 \
		Data::Serializer::Persistent.3 \
		Data::Serializer::PHP::Serialization.3 \
		Data::Serializer::Raw.3 \
		Data::Serializer::Storable.3 Data::Serializer::XML::Dumper.3 \
		Data::Serializer::XML::Simple.3 Data::Serializer::YAML.3 \
		Data::Serializer::YAML::Syck.3

.include <bsd.port.mk>
