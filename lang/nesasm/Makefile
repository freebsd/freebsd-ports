PORTNAME=	nesasm
PORTVERSION=	20040314
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://bobrost.com/nes/files/
DISTNAME=	nbasic_2004_03_14

MAINTAINER=	ninjin@kth.se
COMMENT=	6502 assembler with specific NES support

WRKSRC=		${WRKDIR}/nbasic_2004_03_14/source/${PORTNAME}/source/
USES=		zip

OPTIONS_DEFINE=	DOCS

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^CC/s/=/?=/' \
		-e '/^CFLAGS/{s/=/+=/;s/-O2//;}' \
		${WRKSRC}/Makefile.unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nesasm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}../documentation/*.txt ${STAGEDIR}${DOCSDIR}
	# The next install will overwrite readme.txt with a newer readme.txt
	${INSTALL_DATA} ${WRKSRC}../readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
