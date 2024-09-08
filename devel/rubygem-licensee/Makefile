PORTNAME=	licensee
PORTVERSION=	9.17.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Detects under what license a project is distributed
WWW=		https://github.com/benbalter/licensee

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-dotenv>=2.0<4:misc/rubygem-dotenv \
		rubygem-octokit>=4.20<10:net/rubygem-octokit \
		rubygem-reverse_markdown>=1.0<3:textproc/rubygem-reverse_markdown \
		rubygem-rugged>=0.24<2.0:devel/rubygem-rugged \
		rubygem-thor>=0.19<2.0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/licensee

.include <bsd.port.mk>
