PORTNAME=	gitlab
PORTVERSION=	4.18.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client and CLI for GitLab API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-httparty>=0.18<1:www/rubygem-httparty \
		rubygem-terminal-table>=1.5.1:textproc/rubygem-terminal-table

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gitlab

.include <bsd.port.mk>
