# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	toolame
PORTVERSION=	0.2l
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%200.2/${PORTNAME}%2002l
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimized mpeg 1/2 layer 2 audio encoder

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL.txt

USES=		gmake tar:tgz
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" TWEAKS="${CFLAGS}" ARCH="" PG="" OPTIM=""
USE_CSTD=	gnu89

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PLIST_FILES=	bin/toolame
PORTDOCS=	FUTURE HISTORY LGPL.txt README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toolame ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
