PORTNAME=	lab
PORTVERSION=	${MODVERSION:S/-/./g:R}
DISTVERSIONPREFIX=	v
PORTREVISION=	18
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lab makes it simple to work with repositories on GitLab
WWW=		https://zaquestion.github.io/lab

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
MODVERSION=	0.25.2-0.20230225220034-98c3f01c08e1
GO_MODULE=	github.com/zaquestion/lab@v${MODVERSION}
GO_BUILDFLAGS=	-ldflags="-X main.version=${PORTVERSION}"
PLIST_FILES=	bin/lab

.include <bsd.port.mk>
