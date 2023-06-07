PORTNAME=	nesasm
PORTVERSION=	20040314
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://bobrost.com/nes/files/
DISTNAME=	nbasic_2004_03_14

MAINTAINER=	ninjin@kth.se
COMMENT=	6502 assembler with specific NES support
WWW=		https://bobrost.com/nes/resources.php

LICENSE=	NONE

USES=		zip

WRKSRC=		${WRKDIR}/nbasic_2004_03_14/source/${PORTNAME}/source/

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

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

.include <bsd.port.post.mk>
