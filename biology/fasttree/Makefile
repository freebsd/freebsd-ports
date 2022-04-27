PORTNAME=	FastTree
DISTVERSION=	2.1.10
PORTREVISION=	5
CATEGORIES=	biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments

LICENSE=	GPLv2+

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/FastTree

.if !exists(/usr/include/omp.h)
USES=		compiler:gcc-c++11-lib
.endif

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
