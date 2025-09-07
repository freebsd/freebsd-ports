PORTNAME=	undercover
PORTVERSION=	0.8.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Actionable code coverage - detects untested code blocks in recent changes
WWW=		https://undercover-ci.com/ \
		https://github.com/grodowski/undercover

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-imagen>=0.2.0:devel/rubygem-imagen \
		rubygem-rainbow>=2.1<4.0:devel/rubygem-rainbow \
		rubygem-rugged>=0.27<1.10:devel/rubygem-rugged \
		rubygem-simplecov>=0:devel/rubygem-simplecov \
		rubygem-simplecov_json_formatter>=0:devel/rubygem-simplecov_json_formatter

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/undercover

.include <bsd.port.mk>
