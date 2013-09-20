# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	avce00
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://avce00.maptools.org/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	OpenSource C library convert Arc/Info Vector Coverages to E00

USE_GMAKE=	yes
ALL_TARGET=	default
BIN_FILES=	avcimport avcexport avcdelete avctest ex_avcwrite

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/avcimport bin/avcexport bin/avcdelete \
		bin/avctest bin/ex_avcwrite include/avc.h \
		lib/avc.a

PORTDOCS=	avce00.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	${REINPLACE_CMD} -e 's#gcc#${CC}#g' ${WRKSRC}/GNUmakefile
	${CP} ${WRKSRC}/GNUmakefile ${WRKSRC}/Makefile
.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
	@${REINPLACE_CMD} -e 's#LSB#MSB#g' ${WRKSRC}/Makefile
.endif

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin/
.endfor
	${INSTALL_DATA} ${WRKSRC}/avc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/avc.h ${PREFIX}/include

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/avce00.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
