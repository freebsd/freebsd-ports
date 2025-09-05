PORTNAME=	addlicense
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	devel

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Add license information to source code files
WWW=		https://github.com/google/addlicense \
		https://pkg.go.dev/github.com/google/addlicense

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/google/addlicense

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
