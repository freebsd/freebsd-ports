# $FreeBSD$

PORTNAME=	cointop
PORTVERSION=	1.1.1
CATEGORIES=	finance

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Light cryptocurrency coin stats

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	miguelmota
GH_PROJECT=	cointop

PLIST_FILES=	bin/cointop

do-build:
	 	@${MKDIR} ${WRKSRC}/github.com/${GH_ACCOUNT}
		@${RLN} ${WRKSRC} ${WRKSRC}/github.com/${GH_ACCOUNT}/${PORTNAME}
		@${RLN} ${WRKSRC} ${WRKSRC}/src
		cd ${WRKSRC} && \
			${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
			${GO_CMD} build -ldflags "-X main.Version=${DISTVERSION}" -o bin/${PORTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
