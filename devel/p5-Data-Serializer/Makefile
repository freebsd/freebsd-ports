# New ports collection makefile for:	Data-Serializer
# Date created:	   07 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Data-Serializer
PORTVERSION=	0.49
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modules that serialize data structures

RUN_DEPENDS=	${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
