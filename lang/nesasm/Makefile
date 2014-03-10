# Created by: Pontus Stenetorp <ninjin@kth.se>
# $FreeBSD$

PORTNAME=	nesasm
PORTVERSION=	20040314
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://bobrost.com/nes/files/
DISTNAME=	nbasic_2004_03_14

MAINTAINER=	ninjin@kth.se
COMMENT=	The nesasm assembler is a 6502 assembler with specific NES support

WRKSRC=	${WRKDIR}/nbasic_2004_03_14/source/${PORTNAME}/source/
USES=		zip

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^CC/s/=/?=/' \
		-e '/^CFLAGS/{s/=/+=/;s/-O2//;}' \
		${WRKSRC}/Makefile.unix

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nesasm ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}../documentation/*.txt ${DOCSDIR}
	# The next install will overwrite readme.txt with a newer readme.txt
	${INSTALL_DATA} ${WRKSRC}../readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
