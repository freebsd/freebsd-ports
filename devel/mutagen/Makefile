PORTNAME=	mutagen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.1
PORTREVISION=	1
CATEGORIES=	devel net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Continuous multidirectional synchronization for remote development
WWW=		https://mutagen.io/ \
		https://github.com/mutagen-io/mutagen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/mutagen-io/mutagen
GO_TARGET=	./cmd/mutagen \
		./cmd/mutagen-agent

PLIST_FILES=	bin/mutagen \
		bin/mutagen-agent

.include <bsd.port.mk>
