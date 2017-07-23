# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlang-tools
PORTVERSION=	2.075.0
CATEGORIES=	lang
MASTER_SITES=	https://github.com/dlang/tools/archive/
DISTNAME=	${PORTVERSION:S/^/v/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Ancillary tools for the D programming language compiler

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse

WRKSRC=		${WRKDIR}/tools-${PORTVERSION}
LDC2_CMD=	${LOCALBASE}/bin/ldc2
TOOLS_LIST=	catdoc changed checkwhitespace ddemangle detab dget rdmd tolf

do-build:
.for f in ${TOOLS_LIST}
	${LDC2_CMD} ${WRKSRC}/${f}.d -of=${WRKSRC}/${f}
.endfor
	cd ${WRKSRC}/DustMite && \
		${LDC2_CMD} dustmite.d splitter.d -of=${WRKSRC}/dustmite

do-install:
.for f in ${TOOLS_LIST} dustmite
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/man1/rdmd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
