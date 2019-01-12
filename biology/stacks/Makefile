# $FreeBSD$

PORTNAME=	stacks
DISTVERSION=	2.3
CATEGORIES=	biology perl5 python
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Software pipeline for building loci from short-read sequences

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:openmp gmake python shebangfix

SHEBANG_FILES=	scripts/*.pl scripts/*.py \
		scripts/stacks-integrate-alignments scripts/stacks-gdb
GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
