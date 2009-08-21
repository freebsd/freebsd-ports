# New ports collection makefile for:	devel/p5-Test-Base
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Base
PORTVERSION=	0.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Test::Base - A Data Driven Testing Framework

RUN_DEPENDS=	p5-Spiffy>=0.30:${PORTSDIR}/devel/p5-Spiffy \
		p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Base.3 \
	Test::Base::Filter.3 \
	Module::Install::TestBase.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
RUN_DEPENDS+=	p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
