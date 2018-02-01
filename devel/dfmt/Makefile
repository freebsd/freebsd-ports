# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfmt
PORTVERSION=	0.5.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Formatter for D source code

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse

USE_GITHUB=	yes
GH_ACCOUNT=	dlang-community
GH_TAGNAME=	v${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
