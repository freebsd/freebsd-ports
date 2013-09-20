# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ta2as
PORTVERSION=	0.8.2
CATEGORIES=	converters devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/g}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TASM to AT&T asm syntax converter (GNU AS)

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

USE_ZIP=	yes

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${CP} -f ${FILESDIR}/strtolower.c ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
		's|strlwr|strtolower|' ${WRKSRC}/${PORTNAME}.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} main.c strtolower.c ${PORTNAME}.c \
		-o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
