PORTNAME=	nextdns
PORTVERSION=	1.50.2
DISTVERSIONPREFIX=	v
CATEGORIES=	dns security

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	NextDNS DNS53 to DNS over HTTPS proxy
WWW=		https://github.com/nextdns/nextdns

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_TARGET=	.:${PREFIX}/sbin/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

SUB_FILES=	pkg-message

PLIST_FILES=	sbin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample"

post-install:
	@${STAGEDIR}${PREFIX}/sbin/${PORTNAME} config > ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
