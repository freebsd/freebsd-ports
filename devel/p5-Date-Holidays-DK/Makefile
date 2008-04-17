# New ports collection makefile for:	devel/p5-Date-Holidays-DK
# Date created:				28 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Date-Holidays-DK
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Determine Danish public holidays

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Simple.pm:${PORTSDIR}/devel/p5-Date-Simple \
		${SITE_PERL}/Date/Easter.pm:${PORTSDIR}/devel/p5-Date-Easter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Date::Holidays::DK.3

.include <bsd.port.mk>
