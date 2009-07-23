# New ports collection makefile for:	devel/p5-IO-Lambda
# Date created:				06 Nov 2008
# Whom:					Vany Serezhkin <ivan@serezhkin.com>
#
# $FreeBSD$

PORTNAME=	IO-Lambda
PORTVERSION=	1.11
CATEGORIES=	devel perl5 parallel net www databases
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ivan@serezhkin.com
COMMENT=	Non-blocking I/O in lambda style

BUILD_DEPENDS=	p5-Sub-Name>=0.04:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Net-DNS>=0.64:${PORTSDIR}/dns/p5-Net-DNS \
		p5-libwww>=5.822:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI

RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-IO-Socket-SSL>=1.19:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-AnyEvent>=4.33:${PORTSDIR}/devel/p5-AnyEvent \
		p5-DBI>=1.60.4:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--no-online-tests

MAN3=	IO::Lambda.3 \
	IO::Lambda::Backtrace.3 \
	IO::Lambda::Compat.3 \
	IO::Lambda::DBI.3 \
	IO::Lambda::DNS.3 \
	IO::Lambda::Flock.3 \
	IO::Lambda::Fork.3 \
	IO::Lambda::HTTP.3 \
	IO::Lambda::HTTP::Authen::NTLM.3 \
	IO::Lambda::HTTP::HTTPS.3 \
	IO::Lambda::Loop::AnyEvent.3 \
	IO::Lambda::Loop::Prima.3 \
	IO::Lambda::Loop::Select.3 \
	IO::Lambda::Message.3 \
	IO::Lambda::Mutex.3 \
	IO::Lambda::Poll.3 \
	IO::Lambda::SNMP.3 \
	IO::Lambda::Signal.3 \
	IO::Lambda::Socket.3 \
	IO::Lambda::Thread.3

.include <bsd.port.mk>
