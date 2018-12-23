# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gettext_i18n_rails_js
PORTVERSION=	1.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Make gettext_i18n_rails .po files as JSON

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gettext>=3.0.2:devel/rubygem-gettext \
		rubygem-gettext_i18n_rails>=0.7.1:devel/rubygem-gettext_i18n_rails \
		rubygem-po_to_json>=1.0.0:converters/rubygem-po_to_json \
		rubygem-rails50>=5.0.7:www/rubygem-rails50

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
