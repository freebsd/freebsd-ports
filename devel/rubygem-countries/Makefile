PORTNAME=	countries
PORTVERSION=	4.1.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	All sorts of useful information about every country
WWW=		https://github.com/hexorx/countries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-i18n_data>=0.15.0<0.16.0:devel/rubygem-i18n_data \
		rubygem-sixarm_ruby_unaccent>=1.1<2:textproc/rubygem-sixarm_ruby_unaccent

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
