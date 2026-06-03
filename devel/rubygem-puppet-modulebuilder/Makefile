PORTNAME=	puppet-modulebuilder
DISTVERSION=	2.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Reference implementation for building Puppet modules from source
WWW=		https://github.com/puppetlabs/puppet-modulebuilder

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-minitar0>=0.9<1:archivers/rubygem-minitar0 \
		rubygem-pathspec>=0.2.1:devel/rubygem-pathspec

USES=		gem
NO_ARCH=	yes

.include <bsd.port.mk>
