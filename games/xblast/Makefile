# New ports collection makefile for:    xblast
# Date created:         Sat Nov 08 09:47:12 CET 1997
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	xblast
PORTVERSION=	2.9.22
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= xblast
.ifdef (WITHOUT_SOUND)
PKGNAMESUFFIX=	-nosound
.endif
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	image.tar.gz
DISTFILES+=	level.tar.gz
.ifndef (WITHOUT_SOUND)
DISTFILES+=	sounds.tar.gz
.endif
DIST_SUBDIR=	xblast

MAINTAINER=	se@FreeBSD.org
COMMENT=	Multi-player real-time strategy game for X11

CFLAGS+=	-DGAME_DATADIR='\"${DATADIR}\"'
.ifndef (WITHOUT_SOUND)
CFLAGS+=	-DXBLAST_SOUND
.endif
USE_IMAKE=	yes
.ifndef (WITHOUT_SOUND)
ALL_TARGET=	all xbsndsrv
.endif
MAN1=		xblast.1
.ifndef (WITHOUT_SOUND)
PLIST_SUB+=    WITH_SOUND=""
.else
PLIST_SUB+=    WITH_SOUND="@comment "
.endif

.ifndef (WITHOUT_SOUND)
SOUNDS=		sounds
.endif

post-install:
.ifndef (WITHOUT_SOUND)
		${INSTALL_PROGRAM} ${WRKSRC}/xbsndsrv ${PREFIX}/bin
.endif
		${MKDIR} ${DATADIR}
.for d in image level ${SOUNDS}
		cd ${WRKDIR}; \
		${FIND} $d -type d | (cd ${DATADIR}; ${XARGS} ${MKDIR}); \
		${FIND} $d -type f | ${EGREP} -f ${FILESDIR}/re-${d} | \
		while read f; do \
			${INSTALL_DATA} $$f ${DATADIR}/$$f; \
		done
.endfor

.include <bsd.port.mk>
