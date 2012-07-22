# New ports collection makefile for:	Log::Any::Adapter
# Date created:		28 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Any-Adapter
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to log anywhere

RUN_DEPENDS=	\
	p5-Log-Any>=0.10:${PORTSDIR}/devel/p5-Log-Any \
	p5-Guard>0:${PORTSDIR}/devel/p5-Guard \
	p5-Devel-GlobalDestruction>0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny

PERL_CONFIGURE=	yes

MAN3=	Log::Any::Adapter.3 \
	Log::Any::Adapter::Base.3 \
	Log::Any::Adapter::Development.3 \
	Log::Any::Adapter::File.3 \
	Log::Any::Adapter::Stderr.3 \
	Log::Any::Adapter::Stdout.3

.include <bsd.port.mk>
