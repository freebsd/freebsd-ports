PORTNAME=	archive-tar-minitar
PORTVERSION=	0.12
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and command-line utility for tar archives
WWW=		https://github.com/halostatue/minitar

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

DEPRECATED=	archive-tar-minitar has been deprecated. Use archivers/rubygem-minitar instead
EXPIRATION_DATE=2024-10-31

RUN_DEPENDS=	rubygem-minitar0>=${PORTVERSION}<1:archivers/rubygem-minitar0 \
		rubygem-minitar-cli0>=${PORTVERSION}<1:archivers/rubygem-minitar-cli0

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
