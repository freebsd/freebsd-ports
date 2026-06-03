PORTNAME=	iqtree
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.2
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Efficient phylogenomic software by maximum likelihood
WWW=		http://www.iqtree.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires 64-bit platform with SSE or NEON

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs

USES=		cmake eigen:3
USE_GITHUB=	yes
GH_PROJECT=	iqtree3
GH_TUPLE=	tothuhien:lsd2:c61110f3a4fa05325b45c97b2134792ff9d55d4c:tothuhien/lsd2 \
		iqtree:cmaple:3d45b1ab68e2d68a2825bf17a531e22200578cd6:iqtree/cmaple

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
