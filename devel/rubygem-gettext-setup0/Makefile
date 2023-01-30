PORTNAME=	gettext-setup
PORTVERSION=	0.34
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set up i18n for Ruby projects
WWW=		https://github.com/puppetlabs/gettext-setup-gem

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-fast_gettext1>=1.1<2:devel/rubygem-fast_gettext1 \
		rubygem-gettext>=3.0.2:devel/rubygem-gettext \
		rubygem-locale>=0:devel/rubygem-locale

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.

.include <bsd.port.mk>
