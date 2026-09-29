PORTNAME=	typeprof
PORTVERSION=	0.33.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Type analysis tool for Ruby code
WWW=		https://github.com/ruby/typeprof

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-prism>=1.4.0:textproc/rubygem-prism \
		rubygem-rbs>=3.6.0:devel/rubygem-rbs

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/typeprof

.include <bsd.port.mk>
