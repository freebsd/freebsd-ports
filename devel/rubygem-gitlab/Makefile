PORTNAME=	gitlab
PORTVERSION=	4.20.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client and CLI for GitLab API
WWW=		https://github.com/NARKOZ/gitlab

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-httparty>=0.20<1:www/rubygem-httparty \
		rubygem-terminal-table>=1.5.1:textproc/rubygem-terminal-table

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/gitlab

.include <bsd.port.mk>
