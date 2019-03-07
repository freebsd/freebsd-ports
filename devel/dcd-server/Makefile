# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dcd
PORTVERSION=	0.11.0
DISTVERSIONPREFIX=	v
PORTREVISION?=	0
CATEGORIES?=	devel
PKGNAMESUFFIX?=	-server

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	Auto-complete program for the D programming language (server)

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		rdmd:lang/dlang-tools \
		${LOCALBASE}/lib/d/libemsi_containers.a:devel/containers \
		${LOCALBASE}/lib/d/libdsymbol.a:devel/dsymbol \
		${LOCALBASE}/lib/d/libmsgpack-d.a:devel/msgpack-d \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse \
		${LOCALBASE}/lib/d/libmir-core.a:devel/mir-core \
		${LOCALBASE}/lib/d/libstdx-allocator.a:devel/stdx-allocator

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dlang-community
GH_PROJECT=	DCD

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
DUB_CONFIG?=	server
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && ${DUB_CMD} --config=${DUB_CONFIG}
.if ${PKGNAMESUFFIX} == "-server"
	@cd ${WRKSRC} && ${DUB_CMD} --config=library
.endif

do-install:
	@${MKDIR} ${STAGEDIR}/${D_INCLUDE_DIR}/dcd/${PKGNAMESUFFIX:S/-//}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dcd${PKGNAMESUFFIX} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man1/dcd${PKGNAMESUFFIX}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${WRKSRC}/src/dcd/${PKGNAMESUFFIX:S/-//} && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR}/dcd/${PKGNAMESUFFIX:S/-//} "-name *\.d"
.if ${PKGNAMESUFFIX} == "-server"
	@${MKDIR} ${STAGEDIR}/${D_LIB_DIR}
	@${INSTALL_DATA} ${WRKSRC}/libdcd.a ${STAGEDIR}${D_LIB_DIR}
	@${MKDIR} ${STAGEDIR}/${D_INCLUDE_DIR}/common
	cd ${WRKSRC}/src/dcd/common && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR}/dcd/common "-name *\.d"
.endif

.include <bsd.port.mk>
