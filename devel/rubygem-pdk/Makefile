PORTNAME=	pdk
PORTVERSION=	2.5.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	CLI for development of Puppet modules

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler>=1.15:sysutils/rubygem-bundler \
		rubygem-childprocess>=4.0.0:devel/rubygem-childprocess \
		rubygem-concurrent-ruby>=1.1.5:devel/rubygem-concurrent-ruby \
		rubygem-cri>=2.10.1:devel/rubygem-cri \
		rubygem-deep_merge>=1.1:devel/rubygem-deep_merge \
		rubygem-diff-lcs>=1.4.4:textproc/rubygem-diff-lcs \
		rubygem-facter>=2.5.1:sysutils/rubygem-facter \
		rubygem-ffi>=1.9:devel/rubygem-ffi \
		rubygem-gettext-setup>=0.24:devel/rubygem-gettext-setup \
		rubygem-hitimes>=2.0.0:devel/rubygem-hitimes \
		rubygem-httpclient>=2.8.3:www/rubygem-httpclient \
		rubygem-json_pure>=2.1.0:devel/rubygem-json_pure \
		rubygem-json-schema>=2.8.0:devel/rubygem-json-schema \
		rubygem-minitar>=0.6.1:archivers/rubygem-minitar \
		rubygem-pathspec>=0.2.1:devel/rubygem-pathspec \
		rubygem-tty-prompt>=0.22:devel/rubygem-tty-prompt \
		rubygem-tty-spinner>=0.5:devel/rubygem-tty-spinner \
		rubygem-tty-which>=0.3:devel/rubygem-tty-which

BROKEN_RUBY30=	yes
BROKEN_RUBY31=	yes

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/pdk

.include <bsd.port.mk>
