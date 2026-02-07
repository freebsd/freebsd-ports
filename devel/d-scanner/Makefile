PORTNAME=	d-scanner
PORTVERSION=	0.7.0
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Swiss-army knife for D source code
WWW=		https://github.com/dlang-community/D-Scanner

LICENSE=	BSL

BROKEN=		fails to build

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		rdmd:lang/dlang-tools \
		${LOCALBASE}/lib/d/libemsi_containers.a:devel/containers \
		${LOCALBASE}/lib/d/libdsymbol.a:devel/dsymbol \
		${LOCALBASE}/lib/d/libinifiled.a:devel/inifiled \
		${LOCALBASE}/lib/d/libddoc.a:devel/libddoc \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse \
		${LOCALBASE}/lib/d/libmir-core.a:devel/mir-core \
		${LOCALBASE}/lib/d/libstdx-allocator.a:devel/stdx-allocator \
		rdmd:lang/dlang-tools

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dlang-community
GH_PROJECT=	D-Scanner

PLIST_FILES=	bin/dscanner
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
DC=		${PREFIX}/bin/ldmd2

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && \
		${SETENV} DUB_HOME=${WRKDIR}/dub_home DC=${DC} ${DUB_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dscanner ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
