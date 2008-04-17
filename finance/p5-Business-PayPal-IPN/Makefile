# New ports collection makefile for:   p5-Business-PayPal-IPN
# Date created:		08 September 2008
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Business-PayPal-IPN
PORTVERSION=	1.94
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Perl extension that implements PayPal IPN v1.5

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0.56:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-Crypt-SSLeay>=0.56:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Business::PayPal::IPN.3

.include <bsd.port.mk>
