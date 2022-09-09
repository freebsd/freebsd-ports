PORTNAME=	archive-tar-minitar
PORTVERSION=	0.8
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and command-line utility for tar archives
WWW=		https://github.com/halostatue/minitar

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-minitar>=${PORTVERSION}<1:archivers/rubygem-minitar \
		rubygem-minitar-cli>=${PORTVERSION}<1:archivers/rubygem-minitar-cli

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
