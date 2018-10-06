# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Rose-DateTime
PORTVERSION=	0.540
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DateTime helper functions and objects

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-Rose-Object>=0.82:devel/p5-Rose-Object

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
