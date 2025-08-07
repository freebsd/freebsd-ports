PORTNAME=	zns
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	6
CATEGORIES=	dns

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	CLI tool for querying DNS records with readable and colored output
WWW=		https://github.com/znscli/zns

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/znscli/zns

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		JSON
OPTIONS_DEFAULT=	JSON

JSON_DESC=	Enable JSON output processing support

JSON_RUN_DEPENDS=	jq:textproc/jq

.include <bsd.port.mk>
