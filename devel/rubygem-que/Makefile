PORTNAME=	que
PORTVERSION=	1.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Job queue that uses PostgreSQL advisory locks for speed and reliability

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/que

SHEBANG_FILES=	auto/* \
		scripts/*

.include <bsd.port.mk>
