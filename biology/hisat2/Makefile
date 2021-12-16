PORTNAME=		hisat2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.2.1
PORTREVISION=		2
CATEGORIES=		biology perl5 python

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Alignment program for mapping next-generation sequencing reads

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	64-bit code, some assembly language

BUILD_DEPENDS=	simde>0:devel/simde

USES=		gmake localbase perl5 python shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	hisat2 hisat2-build hisat2-inspect \
		*.py */*.py */*/*.py */*/*/*.py \
		scripts/*.sh evaluation/tests/HLA_novel/scripts/*.sh \
		scripts/*.pl docs_jhu/*.pl
GH_ACCOUNT=	DaehwanKimLab

CFLAGS+=	-Wno-deprecated-declarations -Wno-char-subscripts -fsigned-char

.include <bsd.port.mk>
