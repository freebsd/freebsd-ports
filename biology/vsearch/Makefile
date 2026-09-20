PORTNAME=		vsearch
DISTVERSIONPREFIX=	v
DISTVERSION=		2.32.0
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Versatile open-source tool for metagenomics
WWW=		https://github.com/torognes/vsearch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Explicitly enumerated by upstream developers

BUILD_DEPENDS=	hs-pandoc>0:textproc/hs-pandoc \
		bash>0:shells/bash

USES=		autoreconf ghostscript:build gmake localbase
USE_GITHUB=	yes

GH_ACCOUNT=	torognes
GNU_CONFIGURE=	yes

post-stage:
	${INSTALL_MAN} ${WRKSRC}/man/manpages/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
