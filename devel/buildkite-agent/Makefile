PORTNAME=	buildkite-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	3.97.0
PORTREVISION=	4
CATEGORIES=	devel sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Cross-platform build runner to run your own build tasks
WWW=		https://buildkite.com/

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE LGPL3 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash

USES=		go:1.24,modules

GO_MODULE=	github.com/buildkite/agent/v3
GO_ENV+=	GOTOOLCHAIN=local+path

USE_RC_SUBR=	buildkite

ETCDIR=		${PREFIX}/etc/buildkite

SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -I '' -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
			${WRKSRC}/packaging/linux/scripts/*.sh \
			${WRKSRC}/packaging/linux/root/usr/share/buildkite-agent/*.sh

do-install:
	${INSTALL_PROGRAM} \
		${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ETCDIR}/hooks ${STAGEDIR}${ETCDIR}/plugins
	${INSTALL_DATA} \
		${WRKSRC}/packaging/github/linux/${PORTNAME}.cfg \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.cfg.sample

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/packaging/linux/root/usr/share/${PORTNAME} && ${COPYTREE_SHARE} hooks ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
