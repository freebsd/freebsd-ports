PORTNAME=	doggo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern command-line DNS client (like dig)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/mr-karan/doggo
GO_TARGET=	./cmd/${PORTNAME}/cli

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${MV} bin/cli bin/${PORTNAME}

.include <bsd.port.mk>
