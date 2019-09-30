# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	countries
PORTVERSION=	3.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	All sorts of useful information about every country

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-i18n_data>=0.8.0<0.9.0:devel/rubygem-i18n_data \
		rubygem-sixarm_ruby_unaccent>=1.1.0<2.0.0:textproc/rubygem-sixarm_ruby_unaccent \
		rubygem-unicode_utils>=1.4<2.0:devel/rubygem-unicode_utils

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/console_country3

# binary name has collision with rubygem-apollo_upload_server (/usr/local/bin/console)
post-install:
	${MV} ${STAGEDIR}/${PREFIX}/bin/console ${STAGEDIR}/${PREFIX}/bin/console_country3

.include <bsd.port.mk>
