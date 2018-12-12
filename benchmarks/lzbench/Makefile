# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lzbench
PORTVERSION=	1.7.3
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	In-memory benchmark of open-source LZ77/LZSS/LZMA compressors

USES=		compiler:c11 gmake
USE_GITHUB=	yes
GH_ACCOUNT=	inikep

MAKE_ENV=	CODE_FLAGS=-Wno-c++11-narrowing		# XXX: for clang 6

PLIST_FILES=	bin/lzbench
PORTDOCS=	NEWS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/PROGOS/s,Linux,${OPSYS},' \
		${WRKSRC}/_lzbench/lzbench.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzbench ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
