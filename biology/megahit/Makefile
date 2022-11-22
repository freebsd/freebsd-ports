PORTNAME=		megahit
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.9
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra-fast single-node large and complex metagenomics assembly
WWW=		https://github.com/voutcn/megahit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	"Uses specific 64-bit CPU features"

USES=		cmake python shebangfix
SHEBANG_FILES=	src/megahit
USE_GITHUB=	yes
GH_ACCOUNT=	voutcn

CFLAGS+=	-pthread

.include <bsd.port.mk>
