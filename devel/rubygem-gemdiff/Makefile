PORTNAME=	gemdiff
PORTVERSION=	5.0.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line utility for ruby gems
WWW=		https://github.com/teeparham/gemdiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday-retry>=2.2<3:www/rubygem-faraday-retry \
		rubygem-launchy>=2.4:devel/rubygem-launchy \
		rubygem-octokit8>=8.0<9:net/rubygem-octokit8 \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/gemdiff

.include <bsd.port.mk>
