# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dcd
PORTVERSION=	0.9.1
DISTVERSIONPREFIX=	v
PORTREVISION?=	1
CATEGORIES?=	devel
PKGNAMESUFFIX?=	-server

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	Auto-complete program for the D programming language (server)

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libemsi_containers.a:devel/containers \
		${LOCALBASE}/lib/d/libdsymbol.a:devel/dsymbol \
		${LOCALBASE}/lib/d/libmsgpack-d.a:devel/msgpack-d \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse

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
	@${MKDIR} ${STAGEDIR}/${D_INCLUDE_DIR}/${PKGNAMESUFFIX:S/-//}
	${INSTALL_PROGRAM} ${WRKSRC}/dcd${PKGNAMESUFFIX} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man1/dcd${PKGNAMESUFFIX}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${WRKSRC}/src/${PKGNAMESUFFIX:S/-//} && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR}/${PKGNAMESUFFIX:S/-//} "-name *\.d"
.if ${PKGNAMESUFFIX} == "-server"
	@${MKDIR} ${STAGEDIR}/${D_LIB_DIR}
	@${INSTALL_DATA} ${WRKSRC}/libdcd.a ${STAGEDIR}${D_LIB_DIR}
	@${MKDIR} ${STAGEDIR}/${D_INCLUDE_DIR}/common
	cd ${WRKSRC}/src/common && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR}/common "-name *\.d"
.endif

.include <bsd.port.mk>
