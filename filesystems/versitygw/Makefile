PORTNAME=	versitygw
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	filesystems www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	High-Performance S3 Gateway and Translation Service
WWW=		https://github.com/versity/versitygw/blob/main/go.mod

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	versitygw
GO_MODULE=	github.com/versity/versitygw
GO_TARGET=	./cmd/versitygw

PLIST_DIRS=	/var/log/versitygw
PLIST_FILES=	bin/versitygw

post-install:
	${MKDIR} ${STAGEDIR}/var/log/versitygw

.include <bsd.port.mk>
