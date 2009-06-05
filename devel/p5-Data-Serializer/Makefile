# New ports collection makefile for:	Data-Serializer
# Date created:	   07 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Data-Serializer
PORTVERSION=	0.49
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Modules that serialize data structures

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Data::Serializer.3 Data::Serializer::Config::General.3 \
		Data::Serializer::Cookbook.3 Data::Serializer::Data::Denter.3 \
		Data::Serializer::Data::Dumper.3 Data::Serializer::Data::Taxi.3 \
		Data::Serializer::FreezeThaw.3 Data::Serializer::JSON.3 \
		Data::Serializer::JSON::Syck.3 \
		Data::Serializer::PHP::Serialization.3 \
		Data::Serializer::Storable.3 Data::Serializer::XML::Dumper.3 \
		Data::Serializer::XML::Simple.3 Data::Serializer::YAML.3 \
		Data::Serializer::YAML::Syck.3

.include <bsd.port.mk>
