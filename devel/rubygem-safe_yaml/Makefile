# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	safe_yaml
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Parse YAML safely

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	bundle_install_all_ruby_versions.sh \
		run_specs_all_ruby_versions.sh
PLIST_FILES=	bin/safe_yaml

.include <bsd.port.mk>
