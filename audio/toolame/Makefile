# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	toolame
PORTVERSION=	0.2l
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%200.2/${PORTNAME}%2002l
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Optimized mpeg 1/2 layer 2 audio encoder

OPTIONS_DEFINE=	DOCS

LICENSE=	LGPL21

USES=		gmake
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" TWEAKS="${CFLAGS}" ARCH="" PG="" OPTIM=""
USE_CSTD=	gnu89

PLIST_FILES=	bin/toolame
PORTDOCS=	FUTURE HISTORY LGPL.txt README

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/toolame ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
