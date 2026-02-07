PORTNAME=	avce00
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://avce00.maptools.org/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	OpenSource C library convert Arc/Info Vector Coverages to E00
WWW=		http://avce00.maptools.org/avce00/

OPTIONS_DEFINE=	DOCS

USES=		gmake
ALL_TARGET=	default
BIN_FILES=	avcimport avcexport avcdelete avctest ex_avcwrite

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/avcimport bin/avcexport bin/avcdelete \
		bin/avctest bin/ex_avcwrite include/avc.h \
		lib/avc.a

PORTDOCS=	avce00.html

.include <bsd.port.options.mk>

post-extract:
	${REINPLACE_CMD} -e 's#gcc#${CC}#g' ${WRKSRC}/GNUmakefile
	${CP} ${WRKSRC}/GNUmakefile ${WRKSRC}/Makefile
.if ${ARCH} == "powerpc" || ${ARCH} == powerpc64
	@${REINPLACE_CMD} -e 's#LSB#MSB#g' ${WRKSRC}/Makefile
.endif

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${INSTALL_DATA} ${WRKSRC}/avc.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/avc.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/avce00.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
