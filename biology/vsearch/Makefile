PORTNAME=		vsearch
DISTVERSIONPREFIX=	v
DISTVERSION=		2.27.0
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Versatile open-source tool for metagenomics
WWW=		https://github.com/torognes/vsearch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Explicitly enumerated by upstream developers

USES=		autoreconf ghostscript:build gmake localbase
USE_GITHUB=	yes

GH_ACCOUNT=	torognes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/vsearch share/man/man1/vsearch.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
