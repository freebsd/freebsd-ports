# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ta2as
PORTVERSION=	0.8.2
CATEGORIES=	converters devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/g}_src
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TASM to AT&T asm syntax converter (GNU AS)

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} -f ${FILESDIR}/strtolower.c ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
		's|strlwr|strtolower|' ${WRKSRC}/${PORTNAME}.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} main.c strtolower.c ${PORTNAME}.c \
		-o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
