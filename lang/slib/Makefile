# New ports collection makefile for:   slib
# Date created:        01 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	3b2
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/ \
		http://groups.csail.mit.edu/mac/ftpdir/scm/OLD/
DISTFILES=	slib2d6${EXTRACT_SUFX} \
		slib-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable scheme library

WRKSRC=		${WRKDIR}/slib
USE_GMAKE=	yes
ALL_TARGET=	slib.info
INFO=		slib

post-extract:
	@${RM} ${WRKSRC}/formatst.scm ${WRKSRC}/report.scm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/slib|${PREFIX}/share/slib|' ${WRKSRC}/guile.init

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${WRKSRC}/*.init ${WRKSRC}/*.txt \
		${WRKSRC}/*.xyz ${WRKSRC}/*.ps ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/slib.info ${MANPREFIX}/info
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ANNOUNCE ChangeLog FAQ README
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
