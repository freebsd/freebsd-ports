# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Wnn7
PORTVERSION=	2001.10.17
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://www.omronsoft.co.jp/SP/pcunix/sdk/wnn/
PKGNAMESUFFIX=	-lib
DISTNAME=	Wnn7SDK
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wnn7 client library

USES=		imake
USE_GCC=	any
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/src
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/config/X11.tmpl \
		${WRKSRC}/Makefile.ini
	@${REINPLACE_CMD} -e 's/((/(/' ${WRKSRC}/config/X11.tmpl

# Warning: we cannot use USE_IMAKE.
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make World -f Makefile.ini

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${PREFIX}/include/wnn7/wnn
	${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn7/wnn
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
