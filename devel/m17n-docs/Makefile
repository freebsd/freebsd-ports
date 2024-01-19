PORTNAME=	m17n-docs
PORTVERSION=	1.5.5
CATEGORIES=	devel textproc
MASTER_SITES=	http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	m17n library documentation
WWW=		https://www.nongnu.org/m17n/

NO_BUILD=	yes

OPTIONS_DEFINE=	JAPANESE
JAPANESE_DESC=	Japanese documentation (HTML and PDF)

OPTIONS_SUB=	yes

DOCSDIR=	${PREFIX}/share/doc/m17n

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man3/* ${STAGEDIR}${PREFIX}/share/man/man3
	${INSTALL_MAN} ${WRKSRC}/man/man5/* ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_DATA} ${WRKSRC}/usr/latex/m17n-lib.pdf ${STAGEDIR}${DOCSDIR}/en
	(cd ${WRKSRC}/usr/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/en/)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/ja/latex/m17n-lib.pdf ${STAGEDIR}${DOCSDIR}/ja
	(cd ${WRKSRC}/ja/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/ja/)

.include <bsd.port.mk>
