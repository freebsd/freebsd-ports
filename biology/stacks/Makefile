PORTNAME=	stacks
DISTVERSION=	2.68
CATEGORIES=	biology perl5 python
MASTER_SITES=	https://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Software pipeline for building loci from short-read sequences
WWW=		https://catchenlab.life.illinois.edu/stacks/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python shebangfix
.if !exists(/usr/include/omp.h)
USES+=	compiler:gcc-c++11-lib
.else
USES+=	compiler:c++11-lang
.endif

SHEBANG_FILES=	scripts/*

GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
