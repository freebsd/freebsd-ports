# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	slib
PORTVERSION=	3b6
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/ \
		http://groups.csail.mit.edu/mac/ftpdir/scm/OLD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable scheme library

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake makeinfo

ALL_TARGET=	slib.info
INFO=		slib
NO_ARCH=	yes
PORTDOCS=	ANNOUNCE ChangeLog FAQ README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/slib|${PREFIX}/share/slib|' ${WRKSRC}/guile.init
	@${TOUCH} ${WRKSRC}/*.txi

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} *.scm *.init *.txt \
		*.xyz *.ps ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/slib.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
