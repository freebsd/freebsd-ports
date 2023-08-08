PORTNAME=	gemdiff
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line utility for ruby gems
WWW=		https://github.com/teeparham/gemdiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-launchy>=2.4<3:devel/rubygem-launchy \
		rubygem-octokit4>=4.0<5:net/rubygem-octokit4 \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/gemdiff

.include <bsd.port.mk>
