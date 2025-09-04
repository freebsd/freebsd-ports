PORTNAME=	mutagen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
PORTREVISION=	7
CATEGORIES=	devel net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Continuous multidirectional synchronization for remote development
WWW=		https://mutagen.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/mutagen-io/mutagen
GO_TARGET=	./cmd/mutagen \
		./cmd/mutagen-agent

PLIST_FILES=	bin/mutagen \
		bin/mutagen-agent

.include <bsd.port.mk>
