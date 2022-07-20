PORTNAME=	m17n-docs
PORTVERSION=	1.5.5
CATEGORIES=	devel textproc
MASTER_SITES=	http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	m17n library documentation

NO_BUILD=	yes

OPTIONS_DEFINE=	JAPANESE
JAPANESE_DESC=	Japanese documentation (HTML and PDF)

OPTIONS_SUB=	yes

DOCSDIR=	${PREFIX}/share/doc/m17n

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${STAGEDIR}${MAN3PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/man/man5/* ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/usr/latex/m17n-lib.pdf ${STAGEDIR}${DOCSDIR}/en
	(cd ${WRKSRC}/usr/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/en/)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/ja/latex/m17n-lib.pdf ${STAGEDIR}${DOCSDIR}/ja
	(cd ${WRKSRC}/ja/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/ja/)

.include <bsd.port.mk>
