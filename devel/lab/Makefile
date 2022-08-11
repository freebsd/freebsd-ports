PORTNAME=	lab
PORTVERSION=	0.23.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Lab makes it simple to work with repositories on GitLab

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules

GO_MODULE=	github.com/zaquestion/lab
GO_BUILDFLAGS=	-ldflags="-X main.version=${PORTVERSION}"
PLIST_FILES=	bin/lab

.include <bsd.port.mk>
