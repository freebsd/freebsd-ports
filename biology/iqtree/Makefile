PORTNAME=	iqtree
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	3
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Efficient phylogenomic software by maximum likelihood
WWW=		http://www.iqtree.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fails to compile: unrecognized command line option '-msse3'
BROKEN_powerpc64=	fails to build: GCC version must be at least 4.8!
NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	32-bit compilation is not supported

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		cmake eigen:3
USE_GITHUB=	yes
GH_PROJECT=	iqtree2
GH_TUPLE=	tothuhien:lsd2:c61110f3a4fa05325b45c97b2134792ff9d55d4c:tothuhien/lsd2 \
		iqtree:cmaple:3946f47731699573ed2268e00aa7996a3458d4eb:iqtree/cmaple

PLIST_FILES=	bin/iqtree
PORTEXAMPLES=	custom_distributions.txt example.cf example.nex example.phy \
		models.nex tree.nwk

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/iqtree2 ${STAGEDIR}${PREFIX}/bin/iqtree

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
