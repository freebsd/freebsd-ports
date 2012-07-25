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
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Takes a string composed of various tests, arguments, etc and returns a value

RUN_DEPENDS=	p5-Net-CIDR-Lite>=0.21:${PORTSDIR}/net/p5-Net-CIDR-Lite \
		p5-IO-Socket-SSL>=1.74:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Text-NeatTemplate>=0.10.01:${PORTSDIR}/textproc/p5-Text-NeatTemplate

PERL_CONFIGURE=	yes

MAN3=		Chooser.3

.include <bsd.port.mk>
