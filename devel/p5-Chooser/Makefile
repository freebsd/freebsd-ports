# New ports collection makefile for:	p5-Chooser
# Date created:		2008-06-24
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Chooser
PORTVERSION=	2.0.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Takes a string composed of various tests, arguements, and etc and returns a value

RUN_DEPENDS=	${SITE_PERL}/Net/CIDR/Lite.pm:${PORTSDIR}/net/p5-Net-CIDR-Lite \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/Text/NeatTemplate.pm:${PORTSDIR}/textproc/p5-Text-NeatTemplate

PERL_CONFIGURE=	yes

MAN3=		Chooser.3

.include <bsd.port.mk>
