# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	d-scanner
PORTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/dlang-community/D-Scanner/archive/
DISTNAME=	${DISTVERSION:S/^/v/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Swiss-army knife for D source code

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libemsi_containers.a:devel/containers \
		${LOCALBASE}/lib/d/libdsymbol.a:devel/dsymbol \
		${LOCALBASE}/lib/d/libinifiled.a:devel/inifiled \
		${LOCALBASE}/lib/d/libddoc.a:devel/libddoc \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse

PLIST_FILES=	bin/dscanner
WRKSRC=		${WRKDIR}/${PORTNAME:S/d/D/:S/s/S/}-${PORTVERSION}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dscanner ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
