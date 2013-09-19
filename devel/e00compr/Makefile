# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	e00compr
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://avce00.maptools.org/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library to Read/Write Compressed E00 Files

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/e00conv include/e00compr.h \
		lib/e00compr.a
PORTDOCS=	e00compr.html

.include <bsd.port.options.mk>

post-extract:
	${REINPLACE_CMD} -e 's#gcc#${CC}#g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e00conv ${PREFIX}/bin/e00conv
	${INSTALL_DATA} ${WRKSRC}/e00compr.h ${PREFIX}/include/e00compr.h
	${INSTALL_DATA} ${WRKSRC}/e00compr.a ${PREFIX}/lib/e00compr.a

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/e00compr.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
