# $FreeBSD$

PORTNAME=	haplohseq
DISTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	https://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify regions of allelic imbalance

LICENSE=	MIT

LIB_DEPENDS=	libboost_system.so:devel/boost-libs
RUN_DEPENDS=	R-cran-optparse>0:devel/R-cran-optparse

USES=		compiler:c++11-lang gmake localbase:ldflags python:2.7 tar:xz

OPTIONS_DEFINE=	EXAMPLES

MAKEFILE=	makefile
LDFLAGS+=	-lpthread
MAKE_ENV=	STRIP=${STRIP}

SUB_FILES=	haplohseq-example

post-install-EXAMPLES-on:
	${INSTALL_SCRIPT} ${WRKDIR}/haplohseq-example ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "example ldmap scripts" ${STAGEDIR}${EXAMPLESDIR})

do-test:
	@(cd ${WRKSRC}/build/test && ${FILESDIR}/run-tests)

.include <bsd.port.mk>
