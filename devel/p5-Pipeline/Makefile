# New ports collection makefile for:	p5-Pipeline
# Date Created:				11 June 2006
# Whom:					Rouslan Iskhakov <rouslan@rshell.net>
#
# $FreeBSD$
#

PORTNAME=	Pipeline
PORTVERSION=	3.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RC/RCLAMP
PKGNAMEPREFIX=	p5-

MAINTAINER=	rouslan@rshell.net
COMMENT=	Pipeline - Generic pipeline interface

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/IO/Null.pm:${PORTSDIR}/devel/p5-IO-Null \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/${PERL_ARCH}/Data/Structure/Util.pm:${PORTSDIR}/devel/p5-Data-Structure-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Pipeline::Segment.3 Pipeline::Store::ISA.3 Pipeline.3 \
		Pipeline::Segment::Async::Handler.3 Pipeline::Analyser.3 \
		Pipeline::Production.3 Pipeline::Store::Simple.3 \
		Pipeline::Segment::Async.3 Pipeline::Store.3 \
		Pipeline::Error::Construction.3 Pipeline::Dispatch.3 \
		Pipeline::Base.3 Pipeline::Segment::Async::Fork.3 \
		Pipeline::Error::Abstract.3 Pipeline::Dumper.3 \
		Pipeline::Error::AsyncResults.3 Pipeline::Segment::Tester.3 \
		Pipeline::Segment::Async::IThreads.3

.include <bsd.port.mk>
