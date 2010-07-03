# New ports collection makefile for:	AnyEvent::DBus
# Date created:				2010-06-21
# Whom:					Sahil Tandon <sahil@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-DBus
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Seamlessly integrate Net::DBus into AnyEvent

RUN_DEPENDS=	p5-AnyEvent>=5:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Net-DBus>=0.33:${PORTSDIR}/devel/p5-Net-DBus \
		p5-common-sense>=3.2:${PORTSDIR}/devel/p5-common-sense

MAN3=		AnyEvent::DBus.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
