PORTNAME=	bonnie++
PORTVERSION=	1.98
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.coker.com.au/bonnie++/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O
WWW=		https://www.coker.com.au/bonnie++/

LICENSE=	GPLv2

USES=	shebangfix tar:tgz
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
SHEBANG_FILES=	bon_csv2txt.in

PORTDOCS=	readme.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		's|/usr/share/|${PREFIX}/share/|g' ${WRKSRC}/bonnie++.8

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
