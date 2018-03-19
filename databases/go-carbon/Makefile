# $FreeBSD$

PORTNAME=		go-carbon
DISTVERSIONPREFIX=	v
DISTVERSION=		0.12.0
CATEGORIES=		databases

MAINTAINER=		a.andersson.thn@gmail.com
COMMENT=		Go implementation of carbon

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE.md

BUILD_DEPENDS=		go>=1.8:lang/go

USES=			go

USE_GITHUB=		yes
GH_ACCOUNT=		lomik
USE_RC_SUBR=		${PORTNAME}

USERS=			carbon
GROUPS=			carbon

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC}/_vendor \
		go build --ldflags '-X main.BuildVersion=${DISTVERSION}' github.com/lomik/go-carbon

do-install:
	@${MKDIR} ${STAGEDIR}/var/db/go-carbon
	@${MKDIR} ${STAGEDIR}/var/log/go-carbon
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/go-carbon
	${INSTALL_PROGRAM} ${WRKSRC}/go-carbon ${STAGEDIR}${PREFIX}/bin/
	${INSTALL} ${WRKSRC}/deploy/go-carbon.conf ${STAGEDIR}${PREFIX}/etc/go-carbon/
	${INSTALL} ${WRKSRC}/deploy/storage-aggregation.conf ${STAGEDIR}${PREFIX}/etc/go-carbon/
	${INSTALL} ${WRKSRC}/deploy/storage-schemas.conf ${STAGEDIR}${PREFIX}/etc/go-carbon/

.include <bsd.port.mk>
