PORTNAME=	kafo
PORTVERSION=	7.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby framework to create installers
WWW=		https://github.com/theforeman/kafo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	gsed:textproc/gsed \
		rubygem-ansi>=0:devel/rubygem-ansi \
		rubygem-clamp>=1.3.1<2:devel/rubygem-clamp \
		rubygem-highline1>=1.6.21<3.0:devel/rubygem-highline1 \
		rubygem-kafo_parsers>=0.1.6:devel/rubygem-kafo_parsers \
		rubygem-kafo_wizards>=0:devel/rubygem-kafo_wizards \
		rubygem-logging>=0<3.0.0:devel/rubygem-logging \
		rubygem-powerbar>=0:devel/rubygem-powerbar

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/kafo-configure bin/kafo-export-params bin/kafofy

CPE_VENDOR=	theforeman

.include <bsd.port.mk>
