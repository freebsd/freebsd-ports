# New ports collection makefile for:	Data::MessagePack
# Date created:		22 Dec 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-MessagePack
PORTVERSION=	0.46
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for MessagePack

TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-LeakTrace>0:${PORTSDIR}/devel/p5-Test-LeakTrace

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--xs

MAKE_JOBS_UNSAFE=	yes

MAN3=	Data::MessagePack.3 \
	Data::MessagePack::PP.3 \
	Data::MessagePack::Unpacker.3

.include <bsd.port.mk>
