PORTNAME=	pdk
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	CLI for development of Puppet modules
WWW=		https://github.com/puppetlabs/pdk

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler>=2.1.0,1:sysutils/rubygem-bundler \
		rubygem-childprocess>=5.0.0:devel/rubygem-childprocess \
		rubygem-cri>=2.15.11<3:devel/rubygem-cri \
		rubygem-deep_merge>=1.2.2<2:devel/rubygem-deep_merge \
		rubygem-diff-lcs>=1.5.0:textproc/rubygem-diff-lcs \
		rubygem-facter>=4.0.0<5.0.0:sysutils/rubygem-facter \
		rubygem-ffi>=1.15.5<2.0.0:devel/rubygem-ffi \
		rubygem-hitimes>=2.0.0:devel/rubygem-hitimes \
		rubygem-json_pure>=2.6.3:devel/rubygem-json_pure \
		rubygem-json-schema>=4.0:devel/rubygem-json-schema \
		rubygem-minitar>=0.8:archivers/rubygem-minitar \
		rubygem-pathspec>=1.1:devel/rubygem-pathspec \
		rubygem-puppet_forge>=5.0:sysutils/rubygem-puppet_forge \
		rubygem-puppet-modulebuilder>=1.0,<3.0:devel/rubygem-puppet-modulebuilder \
		rubygem-tty-prompt>=0.23<1:devel/rubygem-tty-prompt \
		rubygem-tty-spinner>=0.9<1:devel/rubygem-tty-spinner \
		rubygem-tty-which>=0.5<1:devel/rubygem-tty-which

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/pdk

.include <bsd.port.mk>
