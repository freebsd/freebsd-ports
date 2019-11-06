# Created by: rene
# $FreeBSD$

PORTNAME=	bas2tap
PORTVERSION=	2.6
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.worldofspectrum.org/pub/sinclair/tools/generic/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//}-generic

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Convert 48k/128k ZX Spectrum BASIC text files to TAP files

BROKEN=		unfetchable

LICENSE=	GPLv2

USES=		zip

NO_WRKSUBDIR=	yes
PORTDOCS=	${PORTNAME}.doc
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME} -lm ${CFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
