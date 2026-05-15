PORTNAME=	diamond
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	BLAST-compatible local sequence aligner
WWW=		http://ab.inf.uni-tuebingen.de/software/diamond/ \
		https://github.com/bbuchfink/diamond

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

USES=		cmake localbase sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	bbuchfink

TEST_TARGET=	test

PLIST_FILES=	bin/diamond

.include <bsd.port.mk>
