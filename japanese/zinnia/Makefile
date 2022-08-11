PORTNAME=	zinnia
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	SF

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Simple, customizable, and portable online handwriting recognition system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	index-ja.html index.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^pkgconfigdir/s!=.*!= ${PREFIX}/libdata/pkgconfig!' \
			${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
