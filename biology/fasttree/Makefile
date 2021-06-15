PORTNAME=	FastTree
DISTVERSION=	2.1.10
PORTREVISION=	5
CATEGORIES=	biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments

LICENSE=	GPLv2+

BROKEN_armv6=		fails to compile: FastTree-2.1.10.c:305:10: 'omp.h' file not found

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/FastTree

.include <bsd.port.options.mk>

.if ${ARCH} == armv7 || ${ARCH} == powerpc
USES=		compiler:gcc-c++11-lib
.endif

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
