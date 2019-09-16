# $FreeBSD$

PORTNAME=	haplohseq
DISTVERSION=	0.1.2
CATEGORIES=	biology
MASTER_SITES=	https://mirror1.hpc.uwm.edu/Distfiles/ \
		https://mirror2.hpc.uwm.edu/Distfiles/
DISTNAME=	haplohseq_source-${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify regions of allelic imbalance

LICENSE=	MIT

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lang gmake localbase:ldflags zip

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/haplohseq_source
LDFLAGS+=	-lpthread
MAKE_ENV=	STRIP=${STRIP}

PLIST_FILES=	bin/haplohseq

do-test:
	@(cd ${WRKSRC}/build/test && ${FILESDIR}/run-tests)

.include <bsd.port.mk>
