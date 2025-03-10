PORTNAME=	chef-winrm-fs
PORTVERSION=	1.3.7
CATEGORIES=	filesystems rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library for file system operations via Windows Remote Management
WWW=		https://github.com/chef/chef-winrm-fs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-winrm>=2.3.11:sysutils/rubygem-chef-winrm \
		rubygem-erubi>=1.7:www/rubygem-erubi \
		rubygem-logging>=1.6.1<3.0:devel/rubygem-logging \
		rubygem-rubyzip>=2.0<3:archivers/rubygem-rubyzip

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rwinrmcp

.include <bsd.port.mk>
