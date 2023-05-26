PORTNAME=	immudb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	databases net
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	Database with built-in cryptographic proof and verification
WWW=		https://immudb.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake go:modules,no_targets
GO_MODULE=	github.com/codenotary/immudb

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' ${WRKSRC}/Makefile

do-install:
.for f in immuadmin immuclient immudb immutest
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}/${PREFIX}/bin/${f}
.endfor

.include <bsd.port.post.mk>
