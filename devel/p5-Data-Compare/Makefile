# New ports collection makefile for:	devel/p5-Data-Compare
# Date created:				25 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Compare
PORTVERSION=	1.2101
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Data::Compare - compare perl data structures

BUILD_DEPENDS=	${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::Compare.3 Data::Compare::Plugins.3 \
		Data::Compare::Plugins::Scalar::Properties.3

.include <bsd.port.mk>
