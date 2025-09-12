PORTNAME=	jjui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3
CATEGORIES=	devel

MAINTAINER=	hoanga@gmail.com
COMMENT=	Terminal user interface for Jujutsu
WWW=		https://github.com/idursun/jjui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	jj:devel/jujutsu

USES=		go:modules

GO_MODULE=	github.com/idursun/jjui@v${DISTVERSION}
GO_PKGNAME=	github.com/idursun/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}

GO_BUILDFLAGS+=	-ldflags "-s -w -X main.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
