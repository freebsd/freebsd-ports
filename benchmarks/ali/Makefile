PORTNAME=	ali
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	benchmarks

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Load testing tool aimed to perform real-time analysis
WWW=		https://github.com/nakabonne/ali

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/nakabonne/ali

CONFLICTS_INSTALL=	ja-mh mmh nmh

PLIST_FILES=	bin/ali

.include <bsd.port.mk>
