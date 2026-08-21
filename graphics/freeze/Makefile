PORTNAME=	freeze
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	graphics

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Generate images of code and terminal output
WWW=		https://github.com/charmbracelet/freeze

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/charmbracelet/freeze
GO_BUILDFLAGS=	-ldflags "-X 'main.Version=${DISTVERSIONPREFIX}${DISTVERSION}'"

PLIST_FILES=	bin/freeze

OPTIONS_DEFINE=	RSVG

RSVG_DESC=		Use rsvg-convert for faster PNG rendering
RSVG_RUN_DEPENDS=	rsvg-convert:graphics/librsvg2-rust

.include <bsd.port.mk>
