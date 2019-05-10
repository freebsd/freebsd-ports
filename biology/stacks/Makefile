# $FreeBSD$

PORTNAME=	stacks
DISTVERSION=	2.4
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

# Force newer GCC on platforms using GCC 4.2 as base
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
