PORTNAME=	neo-cowsay
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
PORTREVISION=	28
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neo Cowsay written in Go
WWW=		https://github.com/Code-Hex/Neo-cowsay

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/Code-Hex/Neo-cowsay/cmd/v2

GO_TARGET=	./cowsay:neo-cowsay ./cowthink:neo-cowthink

PLIST_FILES=	bin/neo-cowsay \
		bin/neo-cowthink

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
