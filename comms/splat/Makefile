# New ports collection makefile for:	splat
# Date created:				8 July 2005
# Whom:					db
#
# $FreeBSD$
#

PORTNAME=	splat
PORTVERSION=	1.3.0
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/ham

MAINTAINER=	db@FreeBSD.org
COMMENT=	Used in calculating path losses, useful to ham radio and others

USE_BZIP2=	yes
PORTDOCS=	README README2 CHANGES
PLIST_FILES=	bin/splat bin/citydecoder bin/usgs2sdf bin/srtm2sdf \
			bin/fontdata bin/bearing
MAN1=		splat.1

do-build:
	@echo "#define MAXPAGES 9" >> ${WRKSRC}/std-parms.h
	@echo "#define HD_MODE 0" >> ${WRKSRC}/std-parms.h
	@cp ${WRKSRC}/std-parms.h ${WRKSRC}/splat.h

	cd ${WRKSRC} && \
		${CXX} ${CXXFLAGS} -lm -lbz2 -o splat itm.cpp splat.cpp
	cd ${WRKSRC}/utils && \
		${CC} ${CFLAGS} -o citydecoder citydecoder.c && \
		${CC} ${CFLAGS} -o usgs2sdf usgs2sdf.c && \
		${CC} ${CFLAGS} -lbz2 -o srtm2sdf srtm2sdf.c && \
		${CC} ${CFLAGS} -lz -o fontdata fontdata.c && \
		${CC} ${CFLAGS} -lz -lm -o bearing bearing.c

do-install:
.for f in splat utils/citydecoder utils/usgs2sdf utils/srtm2sdf \
	utils/fontdata utils/bearing
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/english/man/splat.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
