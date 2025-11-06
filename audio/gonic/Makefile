PORTNAME=	gonic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
PORTREVISION=	2
CATEGORIES=	audio net

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Music streaming server / subsonic server API implementation
WWW=		https://github.com/sentriz/gonic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		mpv:multimedia/mpv

USES=		go:1.25,modules

USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	go.senan.xyz/gonic
GO_TARGET=	./cmd/gonic

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
