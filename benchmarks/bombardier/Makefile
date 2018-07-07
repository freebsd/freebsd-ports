# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bombardier
PORTVERSION=	1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Fast cross-platform HTTP benchmarking tool written in Go

LICENSE=	MIT

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	codesenberg

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${MKDIR} ${WRKDIR}/src/github.com/${GH_ACCOUNT}
	${LN} -s ${WRKSRC} ${WRKDIR}/src/github.com/${GH_ACCOUNT}/${PORTNAME}

do-build:
	cd ${WRKDIR}/src/github.com/${GH_ACCOUNT}/${PORTNAME} && \
		GOPATH=${WRKDIR} go build -ldflags "-X main.version=${PORTVERSION}" .

do-install:
	${INSTALL_PROGRAM} \
		${WRKDIR}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
