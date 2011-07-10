# New ports collection makefile for:	App-SD
# Date created:		2011-04-05
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-SD
PORTVERSION=	0.75
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SPANG
PKGNAMEPREFIX=	p5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	App::SD is a peer-to-peer replicated distributed issue tracker

LICENSE=	MIT

BUILD_DEPENDS=	p5-DateTime>=:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Natural>=0:${PORTSDIR}/devel/p5-DateTime-Format-Natural \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Prophet>=0:${PORTSDIR}/databases/p5-Prophet \
		p5-Test-Script-Run>=0.02:${PORTSDIR}/devel/p5-Test-Script-Run

OPTIONS+=	GITHUB "Enable github sync" on \
		GOOGLECODE "Add support for google code" on \
		HIVEMINDER "Enable huveminder sync" on \
		TRAC "Enable trac sync" on \
		RT "Enable rt sync" on

PERL_CONFIGURE=	yes

MAN3=	App::SD::ForeignReplica::PullEncoder.3 \
	App::SD::Server.3 \
	App::SD::Replica::debbugs.3 \
	App::SD::Replica::rt.3 \
	App::SD::Replica::lighthouse::PullEncoder.3 \
	App::SD::Replica::hm.3 \
	App::SD::Model::Ticket.3 \
	App::SD::Replica::gcode::PullEncoder.3 \
	App::SD::Replica::rt::PullEncoder.3 \
	App::SD::Test.3 \
	App::SD::Replica::trac.3 \
	App::SD::Replica::github.3 \
	App::SD::Replica::github::PullEncoder.3 \
	App::SD::Replica::debbugs::PushEncoder.3 \
	App::SD::Replica::trac::PullEncoder.3 \
	App::SD::CLI::Command.3 \
	App::SD::CLI::Model::Ticket.3 \
	App::SD::Replica::debbugs::PullEncoder.3 \
	App::SD::ForeignReplica.3 \
	App::SD::Util.3 \
	App::SD.3

MAN1=	sd.1

.include <bsd.port.options.mk>

.if defined(WITH_GITHUB)
BUILD_DEPENDS+=	p5-Net-GitHub>=0.18:${PORTSDIR}/net/p5-Net-GitHub
.endif

.if defined(WITH_GOOGLECODE)
BUILD_DEPENDS+=	p5-Net-Google-Code>=0.14:${PORTSDIR}/net/p5-Net-Google-Code
.endif

.if defined(WITH_HIVEMINDER)
BUILD_DEPENDS+=	p5-Net-Jifty>=0.09:${PORTSDIR}/net/p5-Net-Jifty \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address
.endif

.if defined(WITH_TRAC)
BUILD_DEPENDS+=	p5-Net-Trac>=0.13:${PORTSDIR}/www/p5-Net-Trac
.endif

.if defined(WITH_RT)
BUILD_DEPENDS+=	p5-RT-Client-REST>=0:${PORTSDIR}/www/p5-RT-Client-REST
.endif

RUN_DEPENDS:=	${BUILD_DEPENDS}

.include <bsd.port.mk>
