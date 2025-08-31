PORTNAME=	gowall
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Versatile tool to process images
WWW=		https://github.com/Achno/gowall

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		go:1.22,modules

GO_MODULE=	github.com/Achno/gowall

PLIST_FILES=	bin/gowall

OPTIONS_DEFINE=		PREVIEW
OPTIONS_DEFAULT=	PREVIEW
PREVIEW_DESC=		Enable image preview support using chafa
PREVIEW_RUN_DEPENDS=	chafa:graphics/chafa

.include <bsd.port.mk>
