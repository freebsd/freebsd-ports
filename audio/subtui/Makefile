PORTNAME=		SubTUI
DISTVERSIONPREFIX=	v
DISTVERSION=		2.5.1
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

.include <bsd.port.mk>
