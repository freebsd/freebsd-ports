PORTNAME=	sq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.48.5
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	CLI tool for querying multiple databases and data formats
WWW=		https://sq.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	neilotoole

GO_MODULE=	github.com/neilotoole/sq

PLIST_FILES=	bin/sq

.include <bsd.port.mk>
