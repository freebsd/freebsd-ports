PORTNAME=	countries
PORTVERSION=	3.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	All sorts of useful information about every country

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-i18n_data>=0.10.0<0.11.0:devel/rubygem-i18n_data \
		rubygem-sixarm_ruby_unaccent>=1.1<2:textproc/rubygem-sixarm_ruby_unaccent \
		rubygem-unicode_utils>=1.4<2:devel/rubygem-unicode_utils

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
