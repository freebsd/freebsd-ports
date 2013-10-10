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

USES=		gmake
ALL_TARGET=	slib.info
INFO=		slib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/slib|${PREFIX}/share/slib|' ${WRKSRC}/guile.init

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${WRKSRC}/*.init ${WRKSRC}/*.txt \
		${WRKSRC}/*.xyz ${WRKSRC}/*.ps ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/slib.info ${STAGEDIR}${MANPREFIX}/info
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ANNOUNCE ChangeLog FAQ README
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
