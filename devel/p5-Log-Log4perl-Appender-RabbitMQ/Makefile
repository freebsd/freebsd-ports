# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Log4perl-Appender-RabbitMQ
PORTVERSION=	0.102220
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BUNDACIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module which allows logging to RabbitMQ via log4perl

RUN_DEPENDS=	${LOCALBASE}/bin/l4p-tmpl:devel/p5-Log-Log4perl \
		p5-Net-RabbitMQ>0:net/p5-Net-RabbitMQ \
		p5-Readonly>0:devel/p5-Readonly \

BUILD_DEPENDS=	${LOCALBASE}/bin/l4p-tmpl:devel/p5-Log-Log4perl \
		p5-Net-RabbitMQ>0:net/p5-Net-RabbitMQ \
		p5-Readonly>0:devel/p5-Readonly \
		p5-Test-Output>0:devel/p5-Test-Output \
		p5-Test-Net-RabbitMQ>0:devel/p5-Test-Net-RabbitMQ

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
