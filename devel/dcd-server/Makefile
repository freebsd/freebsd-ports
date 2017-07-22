# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dcd
PORTVERSION=	0.9.0
CATEGORIES?=	devel
MASTER_SITES=	https://github.com/dlang-community/DCD/archive/
PKGNAMESUFFIX?=	-server
DISTNAME=	${PORTVERSION:S/^/v/}
DIST_SUBDIR=	${PORTNAME}-server

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	Auto-complete program for the D programming language (server)

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libemsi_containers.a:devel/containers \
		${LOCALBASE}/lib/d/libdsymbol.a:devel/dsymbol \
		${LOCALBASE}/lib/d/libmsgpack-d.a:devel/msgpack-d \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse

PLIST_FILES=	bin/dcd-${PKGNAMESUFFIX:S/-//} \
		man/man1/dcd${PKGNAMESUFFIX}.1.gz
WRKSRC=		${WRKDIR}/${PORTNAME:tu}-${PORTVERSION}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release --config=${DUB_CONFIG}
DUB_CONFIG?=	server

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcd${PKGNAMESUFFIX} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man1/dcd${PKGNAMESUFFIX}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
