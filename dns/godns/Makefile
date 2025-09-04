PORTNAME=	godns
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.4
PORTREVISION=	5
CATEGORIES=	dns
MASTER_SITES=	https://raw.githubusercontent.com/TimothyYe/${PORTNAME}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Dynamic DNS client (DDNS) with optional external reporting features
WWW=		https://github.com/TimothyYe/godns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	yes

GH_ACCOUNT=	TimothyYe
GO_MODULE=	github.com/TimothyYe/godns
GO_TARGET=	./cmd/${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${PATCH_WRKSRC}/cmd/godns/godns.go
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
		${PATCH_WRKSRC}/cmd/godns/godns.go
	${MKDIR} ${PATCH_WRKSRC}/internal/server/out
	${TOUCH} ${PATCH_WRKSRC}/internal/server/out/index.html

post-install:
	${INSTALL_DATA} ${FILESDIR}/godns-config.json.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
