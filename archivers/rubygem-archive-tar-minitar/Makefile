# $FreeBSD$

PORTNAME=	archive-tar-minitar
PORTVERSION=	0.6.1
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and command-line utility for tar archives

LICENSE=	BSD3CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-minitar>=${PORTVERSION:R}:archivers/rubygem-minitar \
		rubygem-minitar-cli>=${PORTVERSION:R}:archivers/rubygem-minitar-cli

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
