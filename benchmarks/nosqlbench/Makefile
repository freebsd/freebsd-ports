# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nosqlbench
PORTVERSION=	0.0.${DATE}
CATEGORIES=	benchmarks databases
MASTER_SITES=	LOCAL/vg

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Micro-benchmarking NoSQL storage

LIB_DEPENDS=	libtarantool.so:${PORTSDIR}/databases/tarantool

DATE=		20120802
USE_BZIP2=	yes
USES=		cmake
CMAKE_ARGS=	-DLIBTNT_INCLUDE=${LOCALBASE}/include \
		-DLIBTNT_LIB=${LOCALBASE}/lib

pre-configure:
	${REINPLACE_CMD} 's#DESTINATION doc#DESTINATION ${DOCSDIR}#g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
