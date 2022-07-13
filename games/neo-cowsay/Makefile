PORTNAME=	neo-cowsay
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neo Cowsay written in Go

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/Code-Hex/Neo-cowsay/cmd/v2

GO_TARGET=	./cowsay:neo-cowsay ./cowthink:neo-cowthink

PLIST_FILES=	bin/neo-cowsay \
		bin/neo-cowthink

.include <bsd.port.mk>
