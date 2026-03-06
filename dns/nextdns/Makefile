PORTNAME=	nextdns
PORTVERSION=	1.47.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	dns security

MAINTAINER=	rs@nextdns.io
COMMENT=	NextDNS DNS53 to DNS over HTTPS proxy
WWW=		https://github.com/nextdns/nextdns

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules
GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_TARGET=	.:${PREFIX}/sbin/${PORTNAME}

SUB_FILES=	pkg-message

PLIST_FILES=	sbin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample"

post-install:
	@${STAGEDIR}${PREFIX}/sbin/${PORTNAME} config > ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
