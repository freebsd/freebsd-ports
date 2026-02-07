PORTNAME=	slib
PORTVERSION=	3c1
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/ \
		http://groups.csail.mit.edu/mac/ftpdir/scm/OLD/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Portable scheme library
WWW=		https://people.csail.mit.edu/jaffer/SLIB.html

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
NO_BUILD=	yes

INFO=		slib
PORTDOCS=	ANNOUNCE ChangeLog FAQ README

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} *.scm *.init *.txt \
		*.xyz *.ps ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/slib.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
