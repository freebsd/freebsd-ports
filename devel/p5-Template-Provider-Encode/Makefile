# New ports collection makefile for:	p5-Template-Provider-Encode
# Date created:		2009-01-08
# Whom:			Murilo Opsfelder <mopsfelder@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Template-Provider-Encode
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	Encode templates for Template Toolkit

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template/Provider.pm:${PORTSDIR}/www/p5-Template-Toolkit

PERL_CONFIGURE=	yes

MAN3=		Template::Provider::Encode.3 \
		Template::Provider::Encode::Guess.3

.include <bsd.port.mk>
