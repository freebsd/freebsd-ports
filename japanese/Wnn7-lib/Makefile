PORTNAME=	Wnn7
PORTVERSION=	2001.10.17
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	http://www.omronsoft.co.jp/SP/pcunix/sdk/wnn/
PKGNAMESUFFIX=	-lib
DISTNAME=	Wnn7SDK

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wnn7 client library

USES=		imake tar:tgz
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/src
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/config/X11.tmpl \
		${WRKSRC}/Makefile.ini
	@${REINPLACE_CMD} -e 's/((/(/' ${WRKSRC}/config/X11.tmpl

# Warning: we cannot use USE_IMAKE.
do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make World -f Makefile.ini)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/wnn7/wnn
	${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${STAGEDIR}${PREFIX}/include/wnn7/wnn
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
