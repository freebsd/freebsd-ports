PORTNAME=	AnyEvent-IRC
PORTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	irc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Event system independent IRC protocol module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Object-Event>=0.7:devel/p5-Object-Event

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
