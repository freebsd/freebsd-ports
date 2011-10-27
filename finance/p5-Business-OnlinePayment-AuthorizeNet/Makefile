# New ports collection makefile for:	Business::OnlinePayment::AuthorizeNet
# Date created:				24 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Business-OnlinePayment-AuthorizeNet
PORTVERSION=	3.22
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Business::OnlinePayment backend module for Authorize.Net

RUN_DEPENDS=	p5-Business-OnlinePayment>=3:${PORTSDIR}/finance/p5-Business-OnlinePayment \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer

PERL_CONFIGURE=	yes

MAN3=		Business::OnlinePayment::AuthorizeNet.3 \
		Business::OnlinePayment::AuthorizeNet::AIM.3 \
		Business::OnlinePayment::AuthorizeNet::AIM::ErrorCodes.3 \
		Business::OnlinePayment::AuthorizeNet::ARB.3

.include <bsd.port.mk>
