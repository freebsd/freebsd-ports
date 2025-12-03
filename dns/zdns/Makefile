PORTNAME=	zdns
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast CLI DNS lookup tool
WWW=		https://github.com/zmap/zdns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/zmap/zdns/v2

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${CP} ${WRKSRC}/vendor/github.com/zmap/zcrypto/x509/root_linux.go ${WRKSRC}/vendor/github.com/zmap/zcrypto/x509/root_freebsd.go

.include <bsd.port.mk>
