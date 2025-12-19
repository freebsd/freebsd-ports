PORTNAME=	gemdiff
PORTVERSION=	6.0.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line utility for ruby gems
WWW=		https://github.com/teeparham/gemdiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday-retry>=2.2<3:www/rubygem-faraday-retry \
		rubygem-launchy>=3.0<4:devel/rubygem-launchy \
		rubygem-octokit>=9.0<11:net/rubygem-octokit \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/gemdiff

.include <bsd.port.mk>
