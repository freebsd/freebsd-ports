# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	slib
PORTVERSION=	3b4
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/ \
		http://groups.csail.mit.edu/mac/ftpdir/scm/OLD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable scheme library

USES=		gmake makeinfo
ALL_TARGET=	slib.info
INFO=		slib
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/slib|${PREFIX}/share/slib|' ${WRKSRC}/guile.init
	@${TOUCH} ${WRKSRC}/*.txi

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${WRKSRC}/*.init ${WRKSRC}/*.txt \
		${WRKSRC}/*.xyz ${WRKSRC}/*.ps ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/slib.info ${STAGEDIR}${PREFIX}/info

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ANNOUNCE ChangeLog FAQ README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
