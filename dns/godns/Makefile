PORTNAME=	godns
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
CATEGORIES=	dns
MASTER_SITES=	https://raw.githubusercontent.com/TimothyYe/${PORTNAME}/${DISTVERSIONFULL}/:gomod \
		https://github.com/TimothyYe/${PORTNAME}/releases/download/v${DISTVERSION}/:webui
DISTFILES=	go.mod:gomod \
		${PORTNAME}-web-${DISTVERSIONFULL}.zip:webui
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Dynamic DNS client (DDNS) with optional external reporting features
WWW=		https://github.com/TimothyYe/godns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+,modules
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	yes

GH_ACCOUNT=	TimothyYe
GO_MODULE=	github.com/TimothyYe/godns
GO_TARGET=	./cmd/${PORTNAME}

post-extract:
	@if [ ! -d ${WRKSRC}/internal/server/out ]; then \
	    ${MKDIR} ${PATCH_WRKSRC}/internal/server/out ;\
	    (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${_DISTFILES:M*web*} -C ${WRKSRC}/internal/server ${EXTRACT_AFTER_ARGS}) ;\
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${PATCH_WRKSRC}/cmd/godns/godns.go
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/cmd/godns/godns.go

post-install:
	${INSTALL_DATA} ${FILESDIR}/godns-config.json.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
