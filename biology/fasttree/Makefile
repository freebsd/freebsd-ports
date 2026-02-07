PORTNAME=	FastTree
DISTVERSION=	2.1.11
CATEGORIES=	biology
MASTER_SITES=	https://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments
WWW=		https://www.microbesonline.org/fasttree/

LICENSE=	GPLv2+

.if !exists(/usr/include/omp.h)
USES=		compiler:gcc-c++11-lib
.endif

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/FastTree

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
