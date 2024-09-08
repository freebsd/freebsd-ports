PORTNAME=	iqtree
DISTVERSIONPREFIX=	v
DISTVERSION =	2.3.6
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Efficient phylogenomic software by maximum likelihood
WWW=		http://www.iqtree.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fails to compile: unrecognized command line option '-msse3'
BROKEN_armv6=	fails to compile: unrecognized command line options '-m32' and '-msse3'
BROKEN_armv7=	fails to compile: unrecognized command line options '-m32' and '-msse3'
BROKEN_i386=	ld: error: unable to find library -latomic (see bug 230888)
BROKEN_powerpc64=	fails to build: GCC version must be at least 4.8!

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		cmake eigen:3
USE_GITHUB=	yes
GH_PROJECT=	iqtree2
GH_TUPLE=	tothuhien:lsd2:125720d9da1281642053713d9b094d5bff2ce9cf:tothuhien/lsd2

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
