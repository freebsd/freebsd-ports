PORTNAME=	immudb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	17
CATEGORIES=	databases net
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

PATCH_SITES=	https://github.com/codenotary/immudb/commit/
PATCHFILES=	0df15e08d84e89509499a84d1b5266b5612c0301.patch:-p1

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
