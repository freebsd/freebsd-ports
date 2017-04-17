# $FreeBSD$

PORTNAME=	sidekiq-unique-jobs
PORTVERSION=	5.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Ensure only a single copy of a job is in Redis

LICENSE=	WTFPL2
LICENSE_NAME=	Do What The Fuck You Want To Public License version 2
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	rubygem-sidekiq>=4.0:devel/rubygem-sidekiq \
		rubygem-thor>=0:devel/rubygem-thor

USE_RUBY=	yes
USES=		gem shebangfix

SHEBANG_FILES=	rails_example/bin/docker-setup \
		rails_example/dev-entrypoint.sh

NO_ARCH=	yes

PLIST_FILES=	bin/jobs

.include <bsd.port.mk>
