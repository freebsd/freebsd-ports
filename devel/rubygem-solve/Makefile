PORTNAME=	solve
PORTVERSION=	4.0.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby version constraint solver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-molinillo>=0.6<1:devel/rubygem-molinillo \
		rubygem-semverse>=1.1<4.0:devel/rubygem-semverse

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
