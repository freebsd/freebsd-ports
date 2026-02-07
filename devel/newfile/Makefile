PORTNAME=	newfile
PORTVERSION=	1.0.14
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for creating starter files in various languages
WWW=		https://newfile.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	ruby

GNU_CONFIGURE=	yes
NO_ARCH=	yes

PORTDOCS=	newfile.html

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
