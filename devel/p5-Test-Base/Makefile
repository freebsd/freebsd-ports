# New ports collection makefile for:	devel/p5-Test-Base
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Base
PORTVERSION=	0.54
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Test::Base - A Data Driven Testing Framework

BUILD_DEPENDS=	\
		p5-Spiffy>=0.30:${PORTSDIR}/devel/p5-Spiffy \
		p5-MIME-Base64>0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Base.3 \
	Test::Base::Filter.3 \
	Module::Install::TestBase.3

.include <bsd.port.mk>
