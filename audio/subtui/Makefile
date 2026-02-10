PORTNAME=		SubTUI
DISTVERSIONPREFIX=	v
DISTVERSION=		2.2.0
CATEGORIES=		audio

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Lightweight subsonic TUI music player
WWW=		https://github.com/MattiaPun/SubTUI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	mpv>0:multimedia/mpv

USES=		go:1.25+,modules
GO_MODULE=	github.com/MattiaPun/SubTUI/v2

PLIST_FILES=	bin/SubTUI

# Create _$platform.go
pre-patch:
	${CP} ${WRKSRC}/internal/integration/media_linux.go \
		${WRKSRC}/internal/integration/media_freebsd.go

.include <bsd.port.mk>
