PORTNAME=	tools
PORTVERSION=	2.101.0
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
PKGNAMEPREFIX=	dlang-

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Ancillary tools for the D programming language compiler
WWW=		https://github.com/dlang/tools

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse

USE_GITHUB=	yes
GH_ACCOUNT=	dlang

LDC2_CMD=	${LOCALBASE}/bin/ldc2
TOOLS_LIST=	catdoc changed checkwhitespace contributors ddemangle detab dget rdmd tolf

do-build:
.for f in ${TOOLS_LIST}
	${LDC2_CMD} ${WRKSRC}/${f}.d -of=${WRKSRC}/${f}
.endfor
	cd ${WRKSRC}/DustMite && \
		${LDC2_CMD} dustmite.d polyhash.d splitter.d -of=${WRKSRC}/dustmite

do-install:
.for f in ${TOOLS_LIST} dustmite
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/man1/rdmd.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
