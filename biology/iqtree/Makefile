PORTNAME=	iqtree
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Efficient phylogenomic software by maximum likelihood
WWW=		http://www.iqtree.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires 64-bit platform with SSE or NEON

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		cmake eigen:3
USE_GITHUB=	yes
GH_PROJECT=	iqtree3
GH_TUPLE=	tothuhien:lsd2:c61110f3a4fa05325b45c97b2134792ff9d55d4c:tothuhien/lsd2 \
		iqtree:cmaple:29df93e77b7ad159b19e8cdd8150545baa1221ae:iqtree/cmaple

PLIST_FILES=	bin/iqtree
PORTEXAMPLES=	custom_distributions.txt example.cf example.nex example.phy \
		models.nex tree.nwk

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/iqtree3 ${STAGEDIR}${PREFIX}/bin/iqtree

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
