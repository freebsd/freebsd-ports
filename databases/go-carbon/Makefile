PORTNAME=		go-carbon
DISTVERSIONPREFIX=	v
DISTVERSION=		0.12.0
PORTREVISION=	28
CATEGORIES=		databases

MAINTAINER=		a.andersson.thn@gmail.com
COMMENT=		Go implementation of carbon
WWW=		https://github.com/lomik/go-carbon

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE.md

USES=			go

USE_GITHUB=		yes
GH_ACCOUNT=		lomik
USE_RC_SUBR=		${PORTNAME}

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=		-ldflags '-X main.BuildVersion=${DISTVERSION}'

USERS=			carbon
GROUPS=			carbon

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/go-carbon
	@${MKDIR} ${STAGEDIR}/var/log/go-carbon
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/go-carbon
	${INSTALL_DATA} ${WRKSRC}/deploy/go-carbon.conf ${STAGEDIR}${PREFIX}/etc/go-carbon/go-carbon.conf.sample
	${INSTALL_DATA} ${WRKSRC}/deploy/storage-aggregation.conf ${STAGEDIR}${PREFIX}/etc/go-carbon/storage-aggregation.conf.sample
	${INSTALL_DATA} ${WRKSRC}/deploy/storage-schemas.conf ${STAGEDIR}${PREFIX}/etc/go-carbon/storage-schemas.conf.sample

.include <bsd.port.mk>
