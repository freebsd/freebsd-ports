# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0-beta5
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Formatter for D source code

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse

USE_GITHUB=	yes
GH_ACCOUNT=	dlang-community
# FIXME: Remove this once it goes out of beta.
# Side note, 0.5.0-beta.5 was a perfectly reasonable version to be used in
# DISTVERSION.
GH_TAGNAME=	v${DISTVERSION:S/beta/beta./}

PLIST_FILES=	bin/${PORTNAME}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
