# New ports collection makefile for:	splat
# Date created:				8 July 2005
# Whom:					db
#
# $FreeBSD$
#

PORTNAME=	splat
PORTVERSION=	1.1.0
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/ham

MAINTAINER=	db@db.net
COMMENT=	Used in calculating path losses, useful to ham radio and others

PORTDOCS=	README README2 CHANGES
PLIST_FILES=	bin/splat bin/citydecoder bin/usgs2sdf bin/fontdata
MAN1=		splat.1

do-build:
	cd ${WRKSRC} && \
		${CXX} ${CXXFLAGS} -lm -lbz2 -o splat itm.cpp splat.cpp
	cd ${WRKSRC}/utils && \
		${CC} ${CFLAGS} -o citydecoder citydecoder.c && \
		${CC} ${CFLAGS} -o usgs2sdf usgs2sdf.c && \
		${CC} ${CFLAGS} -lz -o fontdata fontdata.c

do-install:
.for f in splat utils/citydecoder utils/usgs2sdf utils/fontdata
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/man/splat.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
