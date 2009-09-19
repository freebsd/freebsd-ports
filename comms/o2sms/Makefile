# New ports collection makefile for:    o2sms
# Date created:				June 13th, 2006
# Whom:	      				Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	o2sms
PORTVERSION=	3.34
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN \
		http://www.mackers.com/projects/o2sms/releases/
MASTER_SITE_SUBDIR=	WWW/MACKERS

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Send SMS messages via the websites of Irish mobile operators

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/Lingua/EN/Squeeze.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Squeeze \
		${SITE_PERL}/TestGen4Web/Runner.pm:${PORTSDIR}/www/p5-TestGen4Web-Runner
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		aftsms.1 \
		o2sms.1 \
		meteorsms.1 \
		vodasms.1
MAN3=		WWW::SMS::IE::aftsms.3 \
		WWW::SMS::IE::iesms.3 \
		WWW::SMS::IE::o2sms.3 \
		WWW::SMS::IE::meteorsms.3 \
		WWW::SMS::IE::vodasms.3

.include <bsd.port.mk>
