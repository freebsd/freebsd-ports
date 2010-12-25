# New ports collection makefile for:	p5-Log-Log4perl-Appender-RabbitMQ
# Date created:		2010-09-09
# Whom:			Steve Wills <swills@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Log4perl-Appender-RabbitMQ
PORTVERSION=	0.102220
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BU/BUNDACIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module which allows logging to RabbitMQ via log4perl

RUN_DEPENDS=	${LOCALBASE}/bin/l4p-tmpl:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Net-RabbitMQ>0:${PORTSDIR}/net/p5-Net-RabbitMQ \
		p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly \

BUILD_DEPENDS=	${LOCALBASE}/bin/l4p-tmpl:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Net-RabbitMQ>0:${PORTSDIR}/net/p5-Net-RabbitMQ \
		p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly \
		p5-Test-Output>0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Net-RabbitMQ>0:${PORTSDIR}/devel/p5-Test-Net-RabbitMQ

MAN3=		Log::Log4perl::Appender::RabbitMQ.3

USE_PERL5=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
