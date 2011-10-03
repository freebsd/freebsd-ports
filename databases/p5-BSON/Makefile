# New ports collection makefile for:	p5-BSON
# Date created:		2011-08-03
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BSON
PORTVERSION=	0.06
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MINIMAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Perl implementation of MongoDB BSON serialization

BUILD_DEPENDS=	p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=	p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash

TEST_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime

PERL_CONFIGURE=	yes

MAN3=		BSON.3 \
		BSON::Binary.3 \
		BSON::Bool.3 \
		BSON::Code.3 \
		BSON::MaxKey.3 \
		BSON::MinKey.3 \
		BSON::ObjectId.3 \
		BSON::String.3 \
		BSON::Time.3 \
		BSON::Timestamp.3

.include <bsd.port.mk>
