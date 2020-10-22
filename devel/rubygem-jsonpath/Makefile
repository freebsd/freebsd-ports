# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonpath
PORTVERSION=	1.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	JsonPath is a way of addressing elements within a JSON object

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-to_regexp>=0.2.1<0.3:devel/rubygem-to_regexp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/jsonpath

.include <bsd.port.mk>
