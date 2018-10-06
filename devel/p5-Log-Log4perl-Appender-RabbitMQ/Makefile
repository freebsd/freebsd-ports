# $FreeBSD$

PORTNAME=	Log-Log4perl-Appender-RabbitMQ
PORTVERSION=	0.200001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ABRAXXA
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module which allows logging to RabbitMQ via log4perl

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/bin/l4p-tmpl:devel/p5-Log-Log4perl \
		p5-Net-AMQP-RabbitMQ>=2.30000:net/p5-Net-AMQP-RabbitMQ \
		p5-Readonly>0:devel/p5-Readonly

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
