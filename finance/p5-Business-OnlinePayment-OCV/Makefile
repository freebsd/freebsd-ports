# New ports collection makefile for:	Business::OnlinePayment::OCV
# Date created:				17 December 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-OCV
PORTVERSION=	0.01
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Business::OnlinePayment backend module for OCV

BUILD_DEPENDS=	${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		${SITE_PERL}/Business/OCV.pm:${PORTSDIR}/finance/p5-Business-OCV
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::OCV.3

.include <bsd.port.mk>
