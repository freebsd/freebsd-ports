# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	AnyEvent-Fork
PORTVERSION=	1.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create new worker processes like fork()

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=6,1:devel/p5-AnyEvent \
		p5-IO-FDPass>=0.2:devel/p5-IO-FDPass \
		p5-Proc-FastSpawn>=0.1:devel/p5-Proc-FastSpawn \
		p5-common-sense>=3.6:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
