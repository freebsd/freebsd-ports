PORTNAME=	winrm-fs
PORTVERSION=	1.3.5
CATEGORIES=	filesystems sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for file system operations via WinRM
WWW=		https://github.com/WinRb/winrm-fs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-erubi>=1.8<2:www/rubygem-erubi \
		rubygem-logging>=1.6.1<3.0:devel/rubygem-logging \
		rubygem-rubyzip-gitlab>=2.0<3:archivers/rubygem-rubyzip-gitlab \
		rubygem-winrm>=2.0<3:sysutils/rubygem-winrm

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rwinrmcp

.include <bsd.port.mk>
