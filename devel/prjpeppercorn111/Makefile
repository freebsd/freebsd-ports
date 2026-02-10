PORTNAME=		prjpeppercorn
DISTVERSIONPREFIX=	v
DISTVERSION=		1.11
CATEGORIES=		devel
MASTER_SITES+=		https://mirror.insane.engineer/gatemate-timings/20260210/:timings
DISTFILES+=		gatemate-timings-latest.tar.gz:timings
DIST_SUBDIR=		${PORTNAME}/${DISTVERSION}
PKGNAMESUFFIX=		111

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	GateMate FPGAs bitstream documentation and tools
WWW=		https://github.com/YosysHQ/prjpeppercorn

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ

CMAKE_SOURCE_PATH=	${WRKSRC}/libgm

# Install additional files required by devel/nextpnr for chip DB building
post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/gatemate && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/gatemate)
	(cd ${WRKSRC}/delay && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/delay)

.include <bsd.port.mk>
