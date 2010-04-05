# New ports collection makefile for:	p5-SMS-SMS77
# Date created:				2010-02-04
# Whom:					Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD$

PORTNAME=	SMS-SMS77
PORTVERSION=	0.01
CATEGORIES=	comms net perl5
MASTER_SITES=	http://www.w3r3wolf.de/files/sms77/
PKGNAMEPREFIX=	p5-

MAINTAINER=	steinex@nognu.de
COMMENT=	Perl interface and script to send SMS via SMS77.de

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

MAN1=		sms77send.1
MAN3=		SMS::SMS77::Message.3 \
		SMS::SMS77.3

USE_PERL=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
