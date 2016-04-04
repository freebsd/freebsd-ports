# Created by: Sahil Tandon <sahil@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-DBus
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Seamlessly integrate Net::DBus into AnyEvent

BUILD_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-Net-DBus>=0.33:devel/p5-Net-DBus \
		p5-common-sense>=3.2:devel/p5-common-sense
RUN_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-Net-DBus>=0.33:devel/p5-Net-DBus \
		p5-common-sense>=3.2:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
