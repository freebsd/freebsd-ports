PORTNAME=	diamond
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.11-1
DISTVERSIONSUFFIX=	-g810a3904
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	BLAST-compatible local sequence aligner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	bbuchfink

PLIST_FILES=	bin/diamond

.include <bsd.port.mk>
