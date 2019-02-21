# $FreeBSD$

PORTNAME=	iqtree
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.10
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Efficient phylogenomic software by maximum likelihood

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: unrecognized command line option '-msse3'
BROKEN_armv6=		fails to compile: unrecognized command line options '-m32' and '-msse3'
BROKEN_armv7=		fails to compile: unrecognized command line options '-m32' and '-msse3'
BROKEN_powerpc64=	fails to build: GCC version must be at least 4.8!

USES=		cmake compiler:openmp eigen:3
USE_GITHUB=	yes
GH_ACCOUNT=	Cibiv
GH_PROJECT=	IQ-TREE

PLIST_FILES=	bin/iqtree
PORTEXAMPLES=	example.cf example.nex example.phy models.nex

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/iqtree ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
