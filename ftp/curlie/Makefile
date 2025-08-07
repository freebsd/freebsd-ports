PORTNAME=	curlie
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.7
PORTREVISION=	29
CATEGORIES=	ftp net www

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Frontend to cURL that adds the ease of use of HTTPie
WWW=		https://curlie.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	rs

GH_TUPLE=	golang:crypto:159ae71589f3:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
