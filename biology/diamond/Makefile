PORTNAME=	diamond
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.13
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	BLAST-compatible local sequence aligner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	bbuchfink

PLIST_FILES=	bin/diamond

.include <bsd.port.mk>
