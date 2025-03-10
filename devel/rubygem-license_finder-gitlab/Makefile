PORTNAME=	license_finder
PORTVERSION=	7.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generate, verify and enforce software licenses
WWW=		https://github.com/pivotal/LicenseFinder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-rubyzip>=1<3:archivers/rubygem-rubyzip \
		rubygem-thor12>=1.2.0<1.3:devel/rubygem-thor12 \
		rubygem-tomlrb>=1.3<2.1:textproc/rubygem-tomlrb \
		rubygem-with_env>=1.1.0<1.1.1:devel/rubygem-with_env \
		rubygem-xml-simple-gitlab>=1.1.9<1.2:textproc/rubygem-xml-simple-gitlab

USES=		gem python:run shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	dlf \
		bin/license_finder_pip.py \
		ci/scripts/*.sh

PLIST_FILES=	bin/license_finder \
		bin/license_finder_pip.py

.include <bsd.port.mk>
