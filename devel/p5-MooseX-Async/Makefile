PORTNAME=	MooseX-Async
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Orphanange of Asynchronous Love Children

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0.56:devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.13:devel/p5-MooseX-AttributeHelpers

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-extract:
	@${RM} ${WRKSRC}/lib/MooseX/._Async.pm

.include <bsd.port.mk>
