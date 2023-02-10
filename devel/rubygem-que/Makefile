PORTNAME=	que
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Job queue that uses PostgreSQL advisory locks for speed and reliability
WWW=		https://github.com/que-rb/que

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/que

SHEBANG_FILES=	auto/* \
		scripts/*

.include <bsd.port.mk>
