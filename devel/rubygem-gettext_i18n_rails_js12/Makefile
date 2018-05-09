# $FreeBSD$

PORTNAME=	gettext_i18n_rails_js
PORTVERSION=	1.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Make gettext_i18n_rails .po files as JSON

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gettext>=3.0.2:devel/rubygem-gettext \
		rubygem-gettext_i18n_rails>=0.7.1:devel/rubygem-gettext_i18n_rails \
		rubygem-po_to_json>=1.0.0:converters/rubygem-po_to_json \
		rubygem-rails4>=3.2.0:www/rubygem-rails4

PORTSCOUT=	limit:^1\.2

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
