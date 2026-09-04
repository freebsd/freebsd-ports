PORTNAME=	pgbot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Read-only observability and health reports for PostgreSQL
WWW=		https://pgbot.dev/ \
		https://github.com/pgrundev/pgbot

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/pgrundev/pgbot
GO_TARGET=	./cmd/pgbot
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		${DOCSDIR}/CHANGELOG.md \
		${DOCSDIR}/README.md \
		${DOCSDIR}/SECURITY.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${GO_WRKSRC}/CHANGELOG.md ${GO_WRKSRC}/README.md \
		${GO_WRKSRC}/SECURITY.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
