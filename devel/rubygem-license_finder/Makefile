# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	license_finder
PORTVERSION=	6.14.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generate, verify and enforce software licenses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-rubyzip>=1<3:archivers/rubygem-rubyzip \
		rubygem-thor10>=1.0.1<1.1:devel/rubygem-thor10 \
		rubygem-tomlrb>=1.3<2.1:textproc/rubygem-tomlrb \
		rubygem-with_env>=1.1.0<1.1.1:devel/rubygem-with_env \
		rubygem-xml-simple>=1.1.5<1.2:textproc/rubygem-xml-simple

USES=		gem python:run shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	dlf \
		bin/license_finder_pip.py \
		ci/scripts/*.sh

PLIST_FILES=	bin/license_finder \
		bin/license_finder_pip.py

.include <bsd.port.mk>
