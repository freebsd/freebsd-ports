PORTNAME=	Wnn7
PORTVERSION=	2001.10.17
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	https://ftp.yz.yamagata-u.ac.jp/pub/linux/momonga/4/SOURCES/
PKGNAMESUFFIX=	-lib
DISTNAME=	Wnn7SDK

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wnn7 client library
WWW=		https://www.omron.com/digital/product_text/

LICENSE=	Wnn7_Client_Library
LICENSE_NAME=	Wnn7 Client Library
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		imake tar:tgz
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/src
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=	llvm:max=14
.endif

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwnn7.so.1

.include <bsd.port.mk>
