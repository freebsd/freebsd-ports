# $FreeBSD$

PORTNAME=	iqtree
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.beta4
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Efficient phylogenomic software by maximum likelihood

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3

USES=		cmake compiler:openmp
USE_GITHUB=	yes
GH_ACCOUNT=	Cibiv

PLIST_FILES=	bin/iqtree example.cf example.nex example.phy models.nex
WRKSRC=		${WRKDIR}/IQ-TREE-${DISTVERSION}

.include <bsd.port.mk>
