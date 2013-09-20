# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	slib
PORTVERSION=	3b3
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/ \
		http://groups.csail.mit.edu/mac/ftpdir/scm/OLD/
DISTFILES=	slib-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable scheme library

USE_GMAKE=	yes
ALL_TARGET=	slib.info
INFO=		slib

NO_STAGE=	yes
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
