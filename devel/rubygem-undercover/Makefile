PORTNAME=	undercover
PORTVERSION=	0.9.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Actionable code coverage - detects untested code blocks in recent changes
WWW=		https://undercover-ci.com/ \
		https://github.com/grodowski/undercover

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-benchmark>=0:benchmarks/rubygem-benchmark \
		rubygem-erubi>=1.13:www/rubygem-erubi \
		rubygem-prism>=1.8<3:textproc/rubygem-prism \
		rubygem-rainbow>=2.1<4.0:devel/rubygem-rainbow \
		rubygem-rugged>=0.27<1.10:devel/rubygem-rugged \
		rubygem-simplecov>=1.0:devel/rubygem-simplecov \
		rubygem-simplecov_json_formatter>=0.1<1:devel/rubygem-simplecov_json_formatter

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/undercover

.include <bsd.port.mk>
