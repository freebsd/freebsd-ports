# $FreeBSD$

PORTNAME=	puppetdb_cli
PORTVERSION=	2.0.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB CLI Tooling

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cri>0:devel/rubygem-cri \
		rubygem-pl-puppetdb-ruby>0:databases/rubygem-pl-puppetdb-ruby

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/puppet-db \
		bin/puppet-query

post-patch:
	${REINPLACE_CMD} -e 's|/etc/puppetlabs|/usr/local/etc|' \
		${WRKSRC}/man/puppetdb_conf.pod

.include <bsd.port.mk>
