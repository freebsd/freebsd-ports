# $FreeBSD$

PORTNAME=	clips
PORTVERSION=	6.30
CATEGORIES=	lang
MASTER_SITES=	SF/clipsrules/CLIPS/${PORTVERSION}/
DISTNAME=	clips_core_source_630

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Tool for Building Expert Systems

LICENSE=	PD
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/readme.txt

USES=		zip

WRKSRC=		${WRKDIR}/${DISTNAME}/core
MAKEFILE=	makefile.gcc
ALL_TARGET=	clips

PLIST_FILES=	bin/clips

post-extract:
	${CP} ${WRKDIR}/${DISTNAME}/makefiles/${MAKEFILE} ${WRKSRC}/

post-patch:
	${REINPLACE_CMD} -e 's#gcc #${CC} ${CFLAGS} #g' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clips ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
